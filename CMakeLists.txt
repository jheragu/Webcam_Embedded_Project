# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

cmake_minimum_required(VERSION 2.8)

#set(CURL_LIBRARY "-lcurl") 
#find_package(CURL REQUIRED)
#include_directories(${CURL_INCLUDE_DIR}) 

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(SOURCE_FILES main.cpp canny.cpp)

project( RecordWebcam )
add_executable( RecordWebcam ${SOURCE_FILES} )

include_directories(include)

target_link_libraries( RecordWebcam ${OpenCV_LIBS})
#target_link_libraries( RecordWebcam ${CURL_LIBRARIES})