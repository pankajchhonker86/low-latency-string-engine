cmake_minimum_required(VERSION 3.15)
project(LowLatencyStringEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable AVX2 SIMD Vectorization
if(MSVC)
    add_compile_options(/arch:AVX2)
else()
    add_compile_options(-mavx2 -O3)
endif()

# Include Headers Folder
include_directories(include)

# Define Core Executable and look inside the src folder for source files
add_executable(string_engine 
    src/main.cpp 
    src/custom_string.cpp
)