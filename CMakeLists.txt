cmake_minimum_required(VERSION 3.15)
project(LD_P1)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets Multimedia REQUIRED)

add_executable(LD_P1 main.cpp)

target_link_libraries(LD_P1 Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Multimedia)