#pragma once
#include <iostream>
#include "macros.h"
#include "Transducer.h"

Transducer createInitialTransducer(const Letter* word, Nat output);

void reduceExcept(Transducer& t, const Letter* word, size_t until);