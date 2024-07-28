cmake_minimum_required(VERSION 3.10)

project(RuleEngine)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(RuleEngine src/main.cpp src/rule_engine.cpp)
add_executable(RuleEngineTests tests/test_rule_engine.cpp src/rule_engine.cpp)
