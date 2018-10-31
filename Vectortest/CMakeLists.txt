file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")
add_executable(${Vectortest} ${srcs} ${hdrs})
target_link_libraries(${Vectortest} ${vectorlib} gtest )
