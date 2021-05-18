project(lab5)

add_executable(oop_exercise_05 main.cpp)

set(MY_FLAGS "-Wall -g -Wextra")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_FLAGS}")
