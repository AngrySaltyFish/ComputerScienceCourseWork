CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS src/*.hpp)


project(YoutubeMusicDownloader)

find_package(Qt5Widgets)
find_package(Qt5WebKitWidgets)
find_library(gumbo PATHS /lib/)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)


add_executable(youtubeGUI ${SOURCES} ${HEADERS})
target_link_libraries(youtubeGUI
  Qt5::Widgets
  Qt5::WebKitWidgets
  /usr/local/lib/libmyhtml-4.so
  gumbo
  )
