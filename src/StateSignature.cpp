#include "StateSignature.h"
#include <algorithm>
    
StateSignature::StateSignature(Transducer& t, State q) {
    isFinal = t.finalStates.count(q) == 1;
    if (isFinal) psiOutput = t.psi[q]; else psiOutput = 0;
    
    for (auto pair : t.delta.transitions[q]) {
        Nat n = t.lambda.output(q, pair.first);
        transitions.push_back(std::make_tuple(pair.first, pair.second, n));
    }

    std::sort(transitions.begin(), transitions.end());
}

void StateSignature::print() const {
    if (isFinal) std::cout << "Final "; else std::cout << "isn't final ";
    if (isFinal) std::cout << "Psi: " << psiOutput << "   ";
    for (auto triple: transitions) {
        std::cout << std::get<0>(triple) << " " << std::get<1>(triple) << " "<< std::get<2>(triple) << "   ";
    }
    std::cout << std::endl;
}

bool StateSignature::operator==(const StateSignature& other) const {
    if (isFinal != other.isFinal)
        return false;
    if (isFinal && psiOutput != other.psiOutput)
        return false;
    
    if (transitions.size() != other.transitions.size())
        return false;
    for (int i = 0; i < transitions.size(); i++) 
        if (transitions[i] != other.transitions[i])
            return false;

    return true;
}


bool StateSignature::operator<(const StateSignature& other) const {
    if (isFinal != other.isFinal)
        return isFinal < other.isFinal;

    if (isFinal && psiOutput != other.psiOutput)
        return psiOutput < other.psiOutput;

    return transitions < other.transitions;
}
