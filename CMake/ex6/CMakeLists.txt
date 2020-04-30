cmake_minimum_required(VERSION 3.5)

project(Main VERSION 0.0.5) # название проекта - версия проекта

configure_file(
    #мы говорим на этапе генерации возьми шаблон config.h.in и подставь там всё как надо
    config.h.in
    #и положи вот сюда
    ${CMAKE_CURRENT_BINARY_DIR}/config.h
    #переменная CMAKE_CURRENT_BINARY_DIR говорит сконфигурируй файл в текущую директорию сборки
    # с названием config.h
)

add_executable(mainLib main.cpp)
set_target_properties(
    mainLib PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)


target_include_directories(
    #эта функция добавляет для таргета configure директорию ${CMAKE_CURRENT_BINARY_DIR} в список инклюдов
    mainLib
    PRIVATE # configure если поставить в зависимость другому таргету то все помеченые как PUBLIC унаследуются во второй таргет а PRIVATE нет
    ${CMAKE_CURRENT_BINARY_DIR}
    #тем самым не имея файла config.h.in в репозитории мы можем его использовать в коде
)
set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/"
)
#симейк мой таргет mainLib хочет слинковаться с библиотекой sumLib поэтому слинкуйся с ней
#мы говорим - найди библиотеку с названием sumLib
find_package(sumLib MODULE REQUIRED)

message("SUMLIB_INCLUDE_DIRS = $SUMLIB_INCLUDE_DIRS}")
message("SUMLIB_LIB = ${SUMLIB_LIB}")

target_include_directories(mainLib PRIVATE ${SUMLIB_INCLUDE_DIRS})
target_link_libraries(mainLib ${SUMLIB_LIB})


