cmake_minimum_required(VERSION 3.16)
project(queue C)

set(CMAKE_C_STANDARD 17)

#add_executable(queue queue-example)

project(OS_labs)

set(TARGET_1 queue-example)
set(SRCS_1 queue.c queue-example.c)

set(TARGET_2 queue-threads)
set(SRCS_2 queue.c queue-threads.c)

add_executable(${TARGET_1} ${SRCS_1})
add_executable(${TARGET_2} ${SRCS_2})

set(CMAKE_C_FLAGS "-g -Wall")
set(CMAKE_C_FLAGS_DEBUG "-g -Wall")

target_link_libraries(${TARGET_1} pthread)
target_link_libraries(${TARGET_2} pthread)
