#set source locations
set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/source)
set(COMMON_DIR ${SOURCE_DIR}/common)

include(${SOURCE_DIR}/interfaces/interfaces.cmake)
include(${SOURCE_DIR}/feature_extractor/tokenizer/StringTokenizer.cmake)
include(${SOURCE_DIR}/feature_extractor/vocabulary/Vocabulary.cmake)
include(${SOURCE_DIR}/feature_extractor/count_vectorizer/CountVectorizer.cmake)
