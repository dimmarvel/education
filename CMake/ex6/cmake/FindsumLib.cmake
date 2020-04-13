set(SUMLIB_ROOT
    "$ENV{SUMLIBDIR}"
    CACHE PATH "sumLib root directory."
)

find_path(
    SUMLIB_INCLUDE_DIRS
    NAMES sumLib.include(CheckStructHasMember)
    HINTS $ENV{SUMLIBDIR}
    PATHS ${SUMLIB_ROOT}
    PATH_SUFFIXES include
)

find_library(
    SUMLIB_LIB
    NAMES sumLib
    HINTS $ENV{SUMLIBDIR}
    PATHS ${SUMLIB_ROOT}
    PATH_SUFFIXES include
    NO_DEFAULT_PATH
)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SUMLIB DEFAULT_MSG 
                                SUMLIB_LIB 
                                SUMLIB_INCLUDE_DIRS)