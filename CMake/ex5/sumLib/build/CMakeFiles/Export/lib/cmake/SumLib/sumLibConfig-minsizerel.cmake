#----------------------------------------------------------------
# Generated CMake target import file for configuration "MinSizeRel".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SumLib::sumLib" for configuration "MinSizeRel"
set_property(TARGET SumLib::sumLib APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(SumLib::sumLib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/sumLib.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS SumLib::sumLib )
list(APPEND _IMPORT_CHECK_FILES_FOR_SumLib::sumLib "${_IMPORT_PREFIX}/lib/sumLib.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
