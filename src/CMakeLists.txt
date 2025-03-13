file(GLOB hdrs "*.h*" "include/*.h*")
file(GLOB srcs "*.cpp")

add_library(sorting STATIC ${srcs} ${hdrs})
target_link_libraries(sorting ${LIBRARY_DEPS})