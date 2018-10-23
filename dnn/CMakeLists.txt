project(dnn)

# list(APPEND CMAKE_PREFIX_PATH "C:/Users/dawudmaxx/Entwirkler/Code/opencv-3.4.3/build")
# find_package(OpenCV REQUIRED)

add_executable(dnn_detect ${CMAKE_CURRENT_SOURCE_DIR}/detect/src/obj_detect.cpp)

target_link_libraries(dnn_detect PRIVATE
	"${OpenCV_LIBS}"
)

target_include_directories(dnn_detect PRIVATE
	"${OpenCV_INCLUDE_DIRS}"
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
)

add_executable(dnn_train ${CMAKE_CURRENT_SOURCE_DIR}/train/src/train.cpp)

add_executable(dnn_test ${CMAKE_CURRENT_SOURCE_DIR}/test/src/test.cpp)