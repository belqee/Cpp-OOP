cmake_minimum_required(VERSION 3.14)

# ������ ������������ �������� �++
set(CMAKE_CXX_STANDARD 17)

# TODO: ������������� ������
project(nsu-repository)

# ������ ��� ������������ ����� �������� ���������
set(exe_name ${PROJECT_NAME})

# ������ ��� ������������ ����� ��������� ��� ������� ������
set(test_name test)

# �������� ������������ ���� �������������� (warnings) � ��������� ���������� ��� ������� ��������������.
# ��������� ������� �����, ����� ��������� ���������� ��� ���������������.
# �� �� ������ ������ /WX � -Werror (�������� ���������� � ����������������), ���� ������� ������� ��������� ��� �������.
if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# ��������� �������� ����������, �.�. ����������, ���������� ��� cpp-�����, ����� main.cpp
# TODO: ��������������� ������ cpp-������
add_library(corelib OBJECT word_counter.cpp)

# ��������� ����������� ���� �������� ���������: ��� main.cpp + �������� ����������
add_executable(${exe_name} main.cpp "head.h")
target_link_libraries(${exe_name} corelib)

# ========== ���, ��� ����, ��������� � ������������ ��� ������ GoogleTest ==========

# ��������� ���������� GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# ��������� ����������� ���� ��������� ��� ������� ������: ��� cpp-����� ������ + �������� ���������� + ���������� gtest_main
# ��� ����������� main.cpp ����� �� �����, �.�. ������� main ����������� � gtest_main
add_executable(${test_name} test.cpp "head.h")
target_link_libraries(${test_name} gtest_main)
target_link_libraries(${test_name} corelib)