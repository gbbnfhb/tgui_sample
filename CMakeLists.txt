cmake_minimum_required(VERSION 3.20)
project(TGUI_Raylib_Sample LANGUAGES CXX)

# C++ 標準
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 実行ファイル
add_executable(main
    src/main.cpp
)

# --- TGUI ---
find_package(TGUI CONFIG REQUIRED)
target_link_libraries(main PRIVATE TGUI::TGUI)

# --- sfml ---
find_package(SFML COMPONENTS Network Graphics Window Audio System CONFIG REQUIRED)
target_link_libraries(main PRIVATE SFML::Network SFML::Graphics SFML::Window SFML::Audio SFML::System)

# 必要なら include ディレクトリを追加
# target_include_directories(main PRIVATE ${TGUI_INCLUDE_DIRS})

# Windows / Linux で追加設定が必要ならここに書く
# 例: Linux の場合 pthread が必要なことがある
# if(UNIX)
#     target_link_libraries(main PRIVATE pthread)
# endif()
