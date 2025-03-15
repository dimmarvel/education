cmake_minimum_required(VERSION 3.16)
project(threads_sorokin)

file(GLOB cpp_files *.cpp)

foreach(cpp_file ${cpp_files})
    get_filename_component(target_name ${cpp_file} NAME_WE)
    add_executable(${target_name} ${cpp_file})
    target_compile_features(${target_name} PRIVATE cxx_std_20)
endforeach()