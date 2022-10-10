cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Aim)

find_package(Qt5 COMPONENTS Core Gui Network Svg Widgets REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(${PROJECT_NAME}
    main.cpp
    client.cpp
    mythreadenter.cpp
    server.cpp
    threadout.cpp
    client.ui
    server.ui
    imagesResurses.qrc)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME}
    PUBLIC Qt5::Core
    Qt5::Gui
    Qt5::Network
    Qt5::Svg
    Qt5::Widgets)
