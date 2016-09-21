##### Files #####
set(GOOGLE_TEST_DIR ${CMAKE_CURRENT_LIST_DIR}/googletest)

include_directories(${GOOGLE_TEST_DIR}/googlemock/include ${GOOGLE_TEST_DIR}/googletest/include)
include_directories(${GOOGLE_TEST_DIR}/googlemock ${GOOGLE_TEST_DIR}/googletest)

# Source files
FILE(GLOB SOURCES ${GOOGLE_TEST_DIR}/googlemock/src/gmock-all.cc ${GOOGLE_TEST_DIR}/googletest/src/gtest-all.cc)

##### Outputs #####

# Create emlib library
add_library(googlemock ${SOURCES})
set(LIBS ${LIBS} googlemock)