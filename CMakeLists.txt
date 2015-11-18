PROJECT (GestionEDT)
set(PROJECT_CONTACT lengagne@gmail.com)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set (GestionEDT_VERSION_MAJOR 2)
set (GestionEDT_VERSION_MINOR 0)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse2 -fpic")
set(CMAKE_VERBOSE_MAKEFILE OFF)

set( LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE})
SET( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin )

foreach(p LIB INCLUDE)
	set(var CMAKE_INSTALL_${p}DIR)
	if(NOT IS_ABSOLUTE "${${var}}")
		set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
	endif()
endforeach()


configure_file ( "${PROJECT_SOURCE_DIR}/config_GestionEDT.h.in"
		 "${PROJECT_SOURCE_DIR}/include/config_GestionEDT.h" )

link_directories(	${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE})

# Perform the proper linking
SET (CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

file(	GLOB_RECURSE
	GestionEDT_SOURCES
	src/* )

FILE ( GLOB_RECURSE
        header_files_GestionEDT
	include/*.h)

# ADD_LIBRARY(GestionEDT SHARED 
# 			${GestionEDT_SOURCES}
# )
# 
# target_link_libraries(  GestionEDT
# 			MogsSothPatternGenerator
# 			${SOTH_LIBRARIES})
			
### Completion for non graphical interface
add_executable(	EDT
				"${CMAKE_CURRENT_SOURCE_DIR}/exe/main.cpp")

# install the library files
install( TARGETS EDT  LIBRARY RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin  COMPONENT main)

### Configure file
configure_file(GestionEDTConfig.cmake.in "${PROJECT_BINARY_DIR}/GestionEDTConfig.cmake" @ONLY)

# install ( 	FILES "${PROJECT_BINARY_DIR}/GestionEDTConfig.cmake"
# 			DESTINATION "${INSTALL_LIB_PATH}/GestionEDT" COMPONENT dev ) 

add_subdirectory(tools)