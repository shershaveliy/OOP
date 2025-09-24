cmake_minimum_required(VERSION 3.12)
project(MyCppProject)

# Настройка компилятора
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Главное приложение
add_executable(my_app main.cpp calculator.cpp)