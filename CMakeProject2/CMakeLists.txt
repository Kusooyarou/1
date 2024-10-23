cmake_minimum_required(VERSION 3.10)

# Название проекта
project(CmakeProject2)

# Устанавливаем стандарт C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Указываем директорию с заголовочными файлами
include_directories(${PROJECT_SOURCE_DIR}/headers)

# Указываем путь к исходным файлам
add_executable(CmakeProject2 src/main.cpp src/matrix.cpp)
