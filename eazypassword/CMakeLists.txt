set(APP_NAME eazypassword)

cmake_minimum_required(VERSION 3.5)

add_subdirectory(framework)
add_subdirectory(plugins)
add_subdirectory(widgets)

message("PLUGINS PATH " $ENV{QT_PLUGIN_PATH})

set (CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets Core Gui REQUIRED)

set (HEADERS )

set (SOURCES 
    main.cpp)

add_executable(${APP_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${APP_NAME} PRIVATE . ./src ./framework ./plugins)

target_link_libraries(${APP_NAME} PRIVATE Qt6::Core)
target_link_libraries(${APP_NAME} PRIVATE Qt6::Gui)
target_link_libraries(${APP_NAME} PRIVATE Qt6::Widgets)

target_link_libraries(${APP_NAME} PRIVATE framework)
target_link_libraries(${APP_NAME} PRIVATE plugins)
target_link_libraries(${APP_NAME} PRIVATE widgets)


add_custom_command(TARGET ${APP_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   $ENV{QT_PLUGIN_PATH}/platforms
                   $<TARGET_FILE_DIR:${APP_NAME}>/platforms)
add_custom_command(TARGET ${APP_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                   $<TARGET_FILE:Qt6::Core> $<TARGET_FILE_DIR:${APP_NAME}>)
add_custom_command(TARGET ${APP_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                   $<TARGET_FILE:Qt6::Gui> $<TARGET_FILE_DIR:${APP_NAME}>)
add_custom_command(TARGET ${APP_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                   $<TARGET_FILE:Qt6::Widgets> $<TARGET_FILE_DIR:${APP_NAME}>)