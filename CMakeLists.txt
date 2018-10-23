cmake_minimum_required (VERSION 3.10)

project(cvt)

SET(CMAKE_DEBUG_POSTFIX "d")

list(APPEND CMAKE_PREFIX_PATH "C:/Users/dawudmaxx/Entwirkler/Code/opencv-3.4.3/build")
find_package(OpenCV REQUIRED)

add_subdirectory(core)
add_subdirectory(dnn)
add_subdirectory(debluring)
add_subdirectory(colorspace)

# create build output directory
# file(MAKE_DIRECTORY ${CVT_OUTPUT_DIR})
