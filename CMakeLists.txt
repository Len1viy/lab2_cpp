# установка версии CMake
cmake_minimum_required(VERSION 3.16)

# название проекта (обязательно)
project(ooplab2)

# установка стандарта языка - C++20
set(CMAKE_CXX_STANDARD 20)

# установка флагов компилятора: CMAKE_CXX_FLAGS += -Wall -Wextra
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# добавление подпроекта с библиотекой
add_subdirectory(cards)

add_subdirectory(deck)
add_subdirectory(input)

# добавление подпроекта с тестами
add_subdirectory(tests)

# создание исполняемого файла для диалоговой программы
add_executable(main main.cpp)

# подключение библиотеки circle к диалоговой программе
target_link_libraries(main cards)
target_link_libraries(main deck)
target_link_libraries(main input)


# для сборки из консоли:
#
# mkdir build   # создание директории для файлов сборки
# cd build      # переход в директорию сборки
# cmake ..      # генерация файлов сборки на основе CMakeLists.txt
# make          # сборка проекта
add_executable(prog2 prog2/prog2.cpp prog2/circle/circle.cpp prog2/circle/circle.h)