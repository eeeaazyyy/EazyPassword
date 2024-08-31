set(APP_NAME widgets)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set (CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

set(HEADERS 
    inputlineedit/inputlineedit.hpp)

set(SOURCES 
    inputlineedit/inputlineedit.cpp)

add_library(${APP_NAME} SHARED ${SOURCES} ${HEADERS})

target_include_directories(${APP_NAME} PRIVATE . ./inputlineedit ./buttons)

target_link_libraries(${APP_NAME} PRIVATE Qt6::Widgets)
target_link_libraries(${APP_NAME} PRIVATE Qt6::Core)
target_link_libraries(${APP_NAME} PRIVATE Qt6::Gui)

install(TARGETS ${APP_NAME} RUNTIME DESTINATION ${INSTALL_DIRECTORY} LIBRARY DESTINATION ${INSTALL_DIRECTORY})
