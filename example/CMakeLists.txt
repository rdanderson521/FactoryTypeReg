add_executable(example main.cpp test.cpp test_iface.cpp)
target_link_libraries(example PRIVATE factory)