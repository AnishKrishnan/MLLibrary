##### Files #####

# Headers
include_directories(${CMAKE_CURRENT_LIST_DIR})

# Source files
FILE(GLOB SRC ${CMAKE_CURRENT_LIST_DIR}/*.cpp)

##### Outputs #####

# Create emlib library
add_library(StringTokenizer ${SRC})
set(LIBS ${LIBS} StringTokenizer)