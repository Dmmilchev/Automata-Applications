# Add executable
add_executable(my_project 
               main.cpp 
               Delta.cpp
               Lambda.cpp)

# Install target
install(TARGETS my_project DESTINATION bin)