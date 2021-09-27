set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/1)

add_executable(trig trigonometry.c)
target_link_libraries(trig m)

add_executable(leapyear leap_year.c)