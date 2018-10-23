project(colorspace)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
	"${OpenCV_LIBS}"
)

target_include_directories(${PROJECT_NAME} PRIVATE
	"${OpenCV_INCLUDE_DIRS}"
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
)