
add_library(${PROJECT_NAME} STATIC movement.cpp pokemon.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME}.run main.cpp)
target_link_libraries(${PROJECT_NAME}.run PUBLIC ${PROJECT_NAME})
