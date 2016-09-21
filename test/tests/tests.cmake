##### Files #####

# Source files
FILE(GLOB SOURCES ${CMAKE_CURRENT_LIST_DIR}/*.cpp)

##### Outputs #####

# Create emlib library
add_library(tests ${SOURCES})
set(LIBS ${LIBS} tests)