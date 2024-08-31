set(APP_NAME framework)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set (CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 COMPONENTS Widgets Core Gui REQUIRED)

set(HEADERS 
    frameworkwindow.hpp)

set(SOURCES 
    frameworkwindow.cpp)

add_library(${APP_NAME} SHARED ${SOURCES} ${HEADERS})

target_include_directories(${APP_NAME} PRIVATE . ./controller ../plugins ../ ./widgets )

target_link_libraries(${APP_NAME} PRIVATE Qt6::Core)
target_link_libraries(${APP_NAME} PRIVATE Qt6::Gui)
target_link_libraries(${APP_NAME} PRIVATE Qt6::Widgets)

target_link_libraries(${APP_NAME} PRIVATE plugins)

install(TARGETS ${APP_NAME}
        RUNTIME DESTINATION ${INSTALL_DIRECTORY} LIBRARY DESTINATION ${INSTALL_DIRECTORY})
