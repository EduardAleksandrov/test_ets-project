# Запуск
# conan install path/to/conan/file --output-folder=build --build=missing
# 
# conan install /home/eduard/Projects/iu7/TESTS_v1/lab1/conanfile.txt -of /home/eduard/Projects/iu7/TESTS_v1/lab1/build-conan --build=missing
# cd build
# 
# source conanbuild.sh  - необязательный элемент
# 
# cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release        - .. значит что файл cmakelists.txt лежит на директорию выше
# cmake --build .
# 
# source deactivate_conanbuild.sh
# 
# ./timer

# vscode .vscode/c_cpp_properties.json    - чтобы vscode не подчеркивал
# {
#     "configurations": [
#         {
#             "name": "Linux",
#             "includePath": [
#                 "${workspaceFolder}/**",
#                 "~/.conan2/**"
#             ],
#             "intelliSenseMode": "linux-gcc-x64",
#             "compilerPath": "/usr/bin/g++"
#         }
#     ],
#     "version": 4
# }


cmake_minimum_required(VERSION 3.16)
project(Tests_lab1)
add_definitions("-std=c++17")
message("cl: ${CONAN_LIBS}")
message("cl: ${PROJECT_SOURCE_DIR}")


#compiler flags
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release) # Release
endif()

include(${PROJECT_SOURCE_DIR}/build-conan/build/Release/generators/conan_toolchain.cmake)
find_package(Boost REQUIRED)

# Include Directories for #include <boost/test/unit_test.hpp>
include_directories(${Boost_INCLUDE_DIRS})


# Specify the source files you want to copy
set(SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/../task/mo_pik.csv
    ${CMAKE_SOURCE_DIR}/../task/mo_temp.csv
    ${CMAKE_SOURCE_DIR}/../testdata/1.test.csv)

# Specify the destination directory (e.g., the path folder in the build directory)
set(DESTINATION_DIR ${CMAKE_CURRENT_BINARY_DIR}/task)

# Create the destination directory if it doesn't exist
file(MAKE_DIRECTORY ${DESTINATION_DIR})

# Copy the file to the destination directory
file(COPY ${SOURCE_FILES} DESTINATION ${DESTINATION_DIR})

message(STATUS "Source files: ${SOURCE_FILES}")


# Include directories
include_directories(../headers)

# Add the main source files
# add_library(one ../main.cpp)
add_library(two ../sources/calc.cpp)

add_executable(1.test 1.test.cpp)

target_link_libraries(1.test boost::boost pthread two)
