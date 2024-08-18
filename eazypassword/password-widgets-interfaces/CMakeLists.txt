set(APP_NAME password-widgets-interfaces)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set (CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(HEADERS 
    ezbutton.hpp
    ezlineedit.hpp
    ezlabel.hpp)

set(SOURCES )

add_library(${APP_NAME} SHARED ${SOURCES} ${HEADERS})

target_include_directories(${APP_NAME} PRIVATE . ./src)

target_link_libraries(${APP_NAME} PRIVATE Qt6::Core)
target_link_libraries(${APP_NAME} PRIVATE Qt6::Gui)
target_link_libraries(${APP_NAME} PRIVATE Qt6::Widgets)

install(TARGETS ${APP_NAME}
        RUNTIME DESTINATION ${INSTALL_DIRECTORY} LIBRARY DESTINATION ${INSTALL_DIRECTORY})
