cmake_minimum_required(VERSION 3.14)

# задаем используемый стандарт —++
set(CMAKE_CXX_STANDARD 17)

# TODO: переименовать проект
project(lab2)

# задаем им€ исполн€емого файла основной программы
set(exe_name ${PROJECT_NAME})

# задаем им€ исполн€емого файла программы дл€ запуска тестов
set(test_name test)

# ¬ключаем отслеживание всех предупреждений (warnings) и запрещаем компил€цию при наличии предупреждений.
# —читаетс€ хорошим тоном, когда программа собираетс€ без предупрреждений.
# Ќо вы можете убрать /WX и -Werror (разрешив компил€цию с предупреждени€ми), если сможете разумно объ€снить своЄ решение.
if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# описываем основную библиотеку, т.е. библиотеку, содержащую все cpp-файлы, кроме main.cpp
# TODO: отредактировать список cpp-файлов
add_library(corelib OBJECT bit_array_class.cpp)

# описываем исполн€емый файл основной программы: это main.cpp + основна€ библиотека
add_executable(${exe_name} main.cpp)
target_link_libraries(${exe_name} corelib)

# ========== все, что ниже, относитс€ к тестированию при помощи GoogleTest ==========

# скачиваем библиотеку GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# описываем исполн€емый файл программы дл€ запуска тестов: это cpp-файлы тестов + основна€ библиотека + библиотека gtest_main
# наш собственный main.cpp здесь не нужен, т.к. функци€ main реализована в gtest_main
add_executable(${test_name} test.cpp)
target_link_libraries(${test_name} gtest_main)
target_link_libraries(${test_name} corelib)