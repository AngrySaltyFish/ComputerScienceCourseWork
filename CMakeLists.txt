CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set (CMAKE_MODULE_PATH /usr/lib/cmake)
set (CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCES *.cpp)
file(GLOB HEADERS *.hpp)


project(YoutubeMusicDownloader)

find_package(Qt5Widgets)
find_package(Qt5WebKitWidgets)
find_package(Qt5Multimedia)
find_package(Qt5Core)
find_package(QtAV)
find_package(Qt5Xml)
find_package(Qt5Sql)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_executable(youtubeGUI ${SOURCES} ${HEADERS})
target_link_libraries(youtubeGUI
  Qt5::Widgets
  Qt5::WebKitWidgets
  Qt5::Core
  Qt5::Xml
  Qt5::Sql
  ${QTAVWIDGETS_LIBRARIES}
  )
