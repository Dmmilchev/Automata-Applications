# Create test executable
add_executable(tests test_example.cpp)

# Link with Catch2
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# Add test
enable_testing()
add_test(NAME tests COMMAND tests)