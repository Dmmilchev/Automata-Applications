cmake_minimum_required(VERSION 3.14)  # Need 3.14 for FetchContent
project(MyProject VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories
include_directories(include)

# Add Catch2 via FetchContent
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0  # or later
)
FetchContent_MakeAvailable(Catch2)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(test)

