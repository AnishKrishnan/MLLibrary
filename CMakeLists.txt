# Base EFM32 CMake file
#
# This can be used as is as a project base, or by adding the efm32-base
# repository as a submodule to another project, copying this CMakeLists file
# to the top level directory, and updating the BASE_LOCATION variable to reflect this
# change

###### Project Environment #####

# Set minimum CMake version
cmake_minimum_required(VERSION 2.8.4)

# Set efm32-base project location
set(BASE_LOCATION .)

##### Project Setup #####

# Set our output target
set(TARGET FSMGenerator)

# Configure project and languages
project(${TARGET} C CXX ASM)

# Set build
if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE DEBUG)
endif()

##### Modules #####

# Libraries can be added to the LIBS variable
# or manually included here.
include(source.cmake)

##### Files #####

# Add project headers
include_directories(${BASE_LOCATION}/include)

# Add project sources
set(SOURCES
	source/main.cpp
)

##### Outputs #####

# Generate executable and link
add_executable(${TARGET} ${SOURCES})
target_link_libraries(${TARGET} ${LIBS})

message(${PROJECT_SOURCE_DIR})

add_custom_target(docs
	COMMAND doxygen Doxyfile.in
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)


##### Post build #####

