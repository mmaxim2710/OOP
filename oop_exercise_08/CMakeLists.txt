project(lab7)

add_executable(oop_exercise_07 point.cpp figure.cpp square.cpp triangle.cpp octagon.cpp main.cpp)

set(MY_FLAGS "-Wall -g -Wextra -pthread")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_FLAGS}")
