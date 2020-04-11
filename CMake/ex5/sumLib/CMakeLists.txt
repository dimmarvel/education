cmake_minimum_required(VERSION 3.5)

project(SumLibrary VERSION 0.0.3) # название проекта - версия проекта

configure_file(
    #мы говорим на этапе генерации возьми шаблон config.h.in и подставь там всё как надо
    config.h.in
    #и положи вот сюда
    ${CMAKE_CURRENT_BINARY_DIR}/config.h
    #переменная CMAKE_CURRENT_BINARY_DIR говорит сконфигурируй файл в текущую директорию сборки
    # с названием config.h
)

add_library(sumLib STATIC sumLib.cpp sumLib.h)
set_target_properties(
    sumLib PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(
    #эта функция добавляет для таргета configure директорию ${CMAKE_CURRENT_BINARY_DIR} в список инклюдов
    sumLib
    PRIVATE # configure если поставить в зависимость другому таргету то все помеченые как PUBLIC унаследуются во второй таргет а PRIVATE нет
    ${CMAKE_CURRENT_BINARY_DIR}
    #тем самым не имея файла config.h.in в репозитории мы можем его использовать в коде
)

#Эта часть команды задает структуру папок которая будет создана после выполнения команды установки
# установи ТАРГЕТ sumlib + сделай EXPORT 
install(TARGETS sumLib EXPORT sumLibTargets
#Библиотеки запихни в папку ЛИБ
    LIBRARY DESTINATION lib
#Библиотеки статические запихни опять в ЛИБ
    ARCHIVE DESTINATION lib
#Инклюды запихни в инклюды
    INCLUDES DESTINATION include
)

#скопировать файл sumLib.h в include папку
install (FILES sumLib.h DESTINATION include)


install(EXPORT sumLibTargets
    FILE sumLibConfig.cmake
    NAMESPACE SumLib::
    DESTINATION lib/cmake/SumLib
)
#cmake .. -DCMAKE_INSTALL_PREFIX=install - это встроенная переменная симейк которую он захардкодит в сборочные файлы
#это пусть куда будет произведена установка нашего проекта