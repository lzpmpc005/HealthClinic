cmake_minimum_required(VERSION 3.16)
project(WeeklyReport VERSION 1.0.0 LANGUAGES CXX)


include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
include_directories(/usr/include)
link_directories(/usr/lib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dependencies/Crow/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers/doctors)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers/patients)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers/appointments)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers/prescriptions)

file(GLOB HEADERS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/headers/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/doctors/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/patients/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/appointments/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/prescriptions/*.hpp)

file(GLOB SOURCES_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/doctors/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/patients/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/appointments/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/prescriptions/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/insurance/*.cpp)

add_executable(cpp_weekly_report main.cpp ${SOURCES_FILES} ${HEADERS_FILES}
        src/insurance.repository.cpp
        src/Item.cpp
        headers/Item.hpp
        headers/InventoryManager.hpp
        src/InventoryManager.cpp
        headers/StockChecker.hpp
        src/StockChecker.cpp
)

find_package(SQLite3 REQUIRED)
target_link_libraries(cpp_weekly_report ${SQLite3_LIBRARIES})
find_package(Threads REQUIRED)
target_link_libraries(cpp_weekly_report pthread)
find_package(Boost REQUIRED COMPONENTS system)
target_link_libraries(cpp_weekly_report ${Boost_LIBRARIES})
target_link_libraries(cpp_weekly_report uuid)
target_link_libraries(cpp_weekly_report dl)

set(CMAKE_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
