cmake_minimum_required(VERSION 3.26)
project(DesktopProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(DesktopProject main.cpp
        include/Employee.h
        include/EmployeeManager.h
        include/CSVHelper.h
        src/Employee.cpp
        src/EmployeeManager.cpp
        src/CSVHelper.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
#add_executable(DesktopProject main.cpp src/EmployeeManager.cpp src/Employee.cpp src/CSVHelper.cpp)


