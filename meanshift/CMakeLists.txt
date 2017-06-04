cmake_minimum_required(VERSION 2.8)
project(MeanShift)
find_package(OpenCV REQUIRED)
add_executable(MeanShift main.cpp)
target_link_libraries(MeanShift ${OpenCV_LIBS})

