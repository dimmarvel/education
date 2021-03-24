cmake_minimum_required( VERSION 3.4.0 )

project( clientlib CXX )

set( SOURCE_LIB client.cpp)

add_library( clientlib SHARED ${SOURCE_LIB} )