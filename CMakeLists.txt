
#Auto Genrated CMake file by aura CLI
#Copyright 2023 Vishal Ahirwar. #replace with your copyright notice.
cmake_minimum_required(VERSION 3.5)
project(ll)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
include_directories(./src/includes)
#@find

if(UNIX)
	find_package(cpr)
endif(UNIX)

if (WIN32)
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG dec9422db3af470641f8b0d90e4b451c4daebf64) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)
endif(WIN32)
set(SOURCE ./src/main.cc)#add your additional source file here!
add_executable(${PROJECT_NAME} ${SOURCE})
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
#@link
target_link_libraries(${PROJECT_NAME} PRIVATE cpr::cpr)
