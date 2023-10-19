cmake_minimum_required(VERSION 3.16)
project(queue C)

set(CMAKE_C_STANDARD 17)

#add_executable(queue queue-example)

project(OS_labs)

set(TARGET_1 queue-example)
set(SRCS_1 queue.c queue-example.c)

set(TARGET_2 queue-threads)
set(SRCS_2 queue.c queue-threads.c)

set(TARGET_3 queue-threads-spinlock)
set(SRCS_3 queue.c queue-threads-spinlock.c)

set(TARGET_4 queue-threads-mutex.c)
set(SRCS_4 queue.c queue-threads-mutex.c)

set(TARGET_5 queue-threads-condition_variable.c)
set(SRCS_5 queue.c queue-threads-condition_variable.c)

set(TARGET_6 queue-threads-semaphore.c)
set(SRCS_6 queue.c queue-threads-semaphore.c)

add_executable(${TARGET_1} ${SRCS_1}
        queue-example.c)

add_executable(${TARGET_2} ${SRCS_2}
        queue-threads.c)

add_executable(${TARGET_3} ${SRCS_3}
        queue-threads-spinlock.c)

add_executable(${TARGET_4} ${SRCS_4}
        queue-threads-mutex.c)

add_executable(${TARGET_5} ${SRCS_5}
        queue-threads-condition_variable.c)

add_executable(${TARGET_6} ${SRCS_6}
        queue-threads-semaphore.c)

set(CMAKE_C_FLAGS "-g -Wall")
set(CMAKE_C_FLAGS_DEBUG "-g -Wall")

target_link_libraries(${TARGET_1} pthread)
target_link_libraries(${TARGET_2} pthread)
target_link_libraries(${TARGET_3} pthread)
target_link_libraries(${TARGET_4} pthread)
target_link_libraries(${TARGET_5} pthread)
target_link_libraries(${TARGET_6} pthread)