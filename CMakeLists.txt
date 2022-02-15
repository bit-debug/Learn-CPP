cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set the project name
project(LEARN)

include_directories(src /opt/homebrew/Cellar/fmt/7.1.3/include /opt/homebrew/Cellar/spdlog/1.8.5/include)

set(SOURCE_FILE "main.cpp" CACHE STRING "User specified source file, default to 'main.cpp'")
# add the executable
add_executable(main ${SOURCE_FILE})