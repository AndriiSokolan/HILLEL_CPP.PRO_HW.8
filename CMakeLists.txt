cmake_minimum_required(VERSION 3.10)

project(HW_08_Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(HW_08
    HW_08.cpp       # Основной файл с main()
    MySharedPtr.hpp # Реализация шаблона
)

target_include_directories(HW_08 PRIVATE ${CMAKE_SOURCE_DIR})
