cmake_minimum_required(VERSION 2.6)

project(cmake_ex_7) # ${PROJECT_NAME}

set(CMAKE_CXX_STANDARD 11)
#or
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2") #wanings ON

file(GLOB CPPF "*.cpp")  #собрать все файлы согласно шаблону(*.cpp) где лежит CMakeLists
file(GLOB HEADERSF "*.h")

add_executable(${PROJECT_NAME} ${CPPF} ${HEADERSF})
#or
#add_executable(${PROJECT_NAME} main.cpp)
#or
#add_executable(${PROJECT_NAME} ${SOURCES})