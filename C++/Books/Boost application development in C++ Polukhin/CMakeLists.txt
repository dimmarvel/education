cmake_minimum_required(VERSION 3.24)
project(run_cpp)

set(CMAKE_CXX_STANDARD 17)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.74.0 COMPONENTS program_options REQUIRED) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(run_cpp 
    #program_options.cpp
    #any.cpp
    variant.cpp
    #next
    #next
    #next
    )
    target_link_libraries(run_cpp ${Boost_LIBRARIES})
endif()