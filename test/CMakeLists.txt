# Base Test CMake file
# This can be used as is as a project base, or by adding the efm32-base
# repository as a submodule to another project, copying this CMakeLists file
# to the top level directory, and updating the BASE_LOCATION variable to reflect this
# change

###### Project Environment #####

# Set minimum CMake version
cmake_minimum_required(VERSION 2.8.4)

# Configure project and languages
project(${TARGET} C CXX ASM)

# Set our output target
set(TARGET runTests)

# Locate GTest
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()
find_package(GMock REQUIRED)
include_directories(${GMOCK_INCLUDE_DIRS})

# Set efm32-base project location
set(BASE_LOCATION .)

##### Project Setup #####



# Set build
if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE DEBUG)
endif()

##### Modules #####

# Libraries can be added to the LIBS variable
# or manually included here.

include(${BASE_LOCATION}/tests/tests.cmake)
include(${BASE_LOCATION}/mocks/mocks.cmake)
include(${PROJECT_SOURCE_DIR}/../source.cmake)

##### Files #####

# Add project headers
include_directories(${BASE_LOCATION}/include)

# Add project sources
set(SOURCES
	${SOURCES}
	main.cpp
)

##### Outputs #####

# Generate executable and link
add_executable(${TARGET} ${SOURCES})
target_link_libraries(${TARGET} ${LIBS} ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} pthread)
# target_link_libraries(${TARGET} ${LIBS} ${GTEST_LIBRARIES} pthread)

add_custom_target(run
	COMMAND runTests -gmock_verbose=info
	DEPENDS runTests
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

##### Post build #####

