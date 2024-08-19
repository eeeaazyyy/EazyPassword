set(APP_NAME plugins)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set (CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 COMPONENTS Core Gui REQUIRED)

set(HEADERS 
    generate-password/passwordgeneratefunc.hpp)

set(SOURCES 
    generate-password/passwordgeneratefunc.cpp)

add_library(${APP_NAME} SHARED ${SOURCES} ${HEADERS})

target_link_libraries(${APP_NAME} PRIVATE Qt6::Core)
target_link_libraries(${APP_NAME} PRIVATE Qt6::Gui)

install(TARGETS ${APP_NAME} RUNTIME DESTINATION ${INSTALL_DIRECTORY} LIBRARY DESTINATION ${INSTALL_DIRECTORY})
