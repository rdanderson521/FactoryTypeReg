add_executable(exampleBasic main.cpp test.cpp test_iface.cpp)
target_link_libraries(exampleBasic PRIVATE factory)