cmake_minimum_required(VERSION 3.5) #

project(cmake_example)

add_executable(helloWorld main.cpp) # сmake собери мне экзешник с имнем helloWorld из main.cpp

set_target_properties( # задать properties для таргета(helloWorld)
    helloWorld PROPERTIES # мы говорим что собирать его нужно:
    CXX_STANDART 11       # стандартом не < 11
    CXX_STANDART_REQUIRED ON # cmake стандарт ТРЕБУЕТСЯ, если проект попадет на машину где стандарт меньше он не даст собраться
    
)