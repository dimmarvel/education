cmake_minimum_required(VERSION 3.5)

project(Example3 VERSION 0.0.1) # название проекта - версия проекта

configure_file(
    #мы говорим на этапе генерации возьми шаблон config.h.in и подставь там всё как надо
    config.h.in
    #и положи вот сюда
    ${CMAKE_CURRENT_BINARY_DIR}/config.h
    #переменная CMAKE_CURRENT_BINARY_DIR говорит сконфигурируй файл в текущую директорию сборки
    # с названием config.h
)

set(SOURCES
    main.cpp
    version.cpp
)
set(HEADERS 
    version.h
)

add_executable(configure ${SOURCES} ${HEADERS})
set_target_properties(
    configure PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(
    #эта функция добавляет для таргета configure директорию ${CMAKE_CURRENT_BINARY_DIR} в список инклюдов
    configure
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    #тем самым не имея файла config.h.in в репозитории мы можем его использовать в коде
)