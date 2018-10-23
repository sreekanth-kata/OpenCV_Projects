project(core)

#list(APPEND CMAKE_PREFIX_PATH "C:/Users/dawudmaxx/Entwirkler/Code/opencv-3.4.3/build")
#find_package(OpenCV REQUIRED)
# find_package(Caffe)
# message(STATUS ${OpenCV_LIBS})


add_executable(core ${CMAKE_CURRENT_SOURCE_DIR}/src/core.cpp)

target_link_libraries(core PRIVATE
	"${OpenCV_LIBS}"
)

target_include_directories(core PRIVATE
	"${OpenCV_INCLUDE_DIRS}"
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
)

# create build output directory
# file(MAKE_DIRECTORY ${CORE_OUTPUT_DIR})