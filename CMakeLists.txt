cmake_minimum_required(VERSION 2.8)

if (CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -O3")
endif (CMAKE_COMPILER_IS_GNUCXX)

file(GLOB srcs ./*.cpp ./*.h*)
add_executable(bspline ${srcs})