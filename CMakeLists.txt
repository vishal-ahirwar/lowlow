project(ll)

#Auto Genrated CMake file by aura CLI
#Copyright 2023 Vishal Ahirwar. #replace with your copyright notice.
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
include_directories(./src/includes)
#@find
find_package(cpr REQUIRED)
set(SOURCE ./src/main.cc)#add your additional source file here!
add_executable(${PROJECT_NAME} ${SOURCE})
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
#@link
target_link_libraries(${PROJECT_NAME} PRIVATE cpr::cpr)
