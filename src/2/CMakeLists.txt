set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/2)

add_executable(loop loop.c)
add_executable(gpa gpa.c)
add_executable(calendar calendar.c)
add_executable(pi pi_series.c)
target_link_libraries(pi m)

add_executable(goldbach goldbach_conjecture.c)
