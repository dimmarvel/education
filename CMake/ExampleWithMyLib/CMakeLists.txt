cmake_minimum_required( VERSION 3.4.0 )
project( net CXX )

set (SOURCE_EXE main.cpp)

include_directories(clientlib) # Расположение заголовочных файлов

add_executable( net ${SOURCE_EXE}) # Создает исполняемый файл с именем main

add_subdirectory(clientlib) # Добавление подпроекта, указывается имя дирректории

target_link_libraries(net clientlib) # Линковка программы с библиотекой