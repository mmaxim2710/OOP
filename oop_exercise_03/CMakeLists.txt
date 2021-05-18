project(lab1)

add_executable(oop_exercise_03 point.cpp figure.cpp octagon.cpp square.cpp triangle.cpp main.cpp)

set(MY_FLAGS "-Wall -g -Wextra")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MYCOMPILE_FLAGS}")
