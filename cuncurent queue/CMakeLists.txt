cmake_minimum_required(VERSION 3.16)
project(queue C)

set(CMAKE_C_STANDARD 17)

#add_executable(queue queue-example)

project(OS_labs)

set(TARGET_1 spinlock_queue.c)
set(SRCS_1 queue.c spinlock_queue.c)

add_executable(${TARGET_1} ${SRCS_1} spinlock_queue.c)

set(CMAKE_C_FLAGS "-g -Wall")
set(CMAKE_C_FLAGS_DEBUG "-g -Wall")

target_link_libraries(${TARGET_1} pthread)