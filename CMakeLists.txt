cmake_minimum_required(VERSION 3.8)
project (prog)

set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")  
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAGS "-g -Wall -std=gnu11 -O0")

# MAIN

add_executable(main src/01_template/main.c)
# target_include_directories(main PUBLIC src)

add_executable(00_playground src/00_playground/main.c)
add_executable(02_File_IO src/02_File_IO/main.c)
add_executable(03_select src/03_select/main.c)
add_executable(04_poll src/04_poll/main.c)
add_executable(05_wait src/05_wait/main.c)
add_executable(06_buffered_IO src/06_buffered_IO/main.c)
add_executable(07_clearerr src/07_clearerr/main.c)
add_executable(08_endianess src/08_endianess/main.c)

# TESTS

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests
  src/tests/gtest_main.cpp
)

target_include_directories(tests PUBLIC
  src/
  src/tests
)

target_link_libraries(tests PUBLIC gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
