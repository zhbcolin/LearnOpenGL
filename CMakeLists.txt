cmake_minimum_required(VERSION 3.16)
project(learn_opengl)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
link_directories("C:/openGL/lib")
include_directories("C:/openGL/include")

add_executable(learn_opengl_1.1 code_1/1_hello_window.cpp src/glad.c)
add_executable(learn_opengl_1.2.1 code_1/2.1_hello_triangle.cpp src/glad.c)
add_executable(learn_opengl_1.2.2 code_1/2.2_hello_triangle_indexed.cpp src/glad.c)
add_executable(learn_opengl_1.2.3 code_1/2.3_hello_triangle_exercise1.cpp src/glad.c)
add_executable(learn_opengl_1.2.4 code_1/2.4_hello_triangle_exercise2.cpp src/glad.c)
add_executable(learn_opengl_1.2.5 code_1/2.5_hello_triangle_exercise3.cpp src/glad.c)
add_executable(learn_opengl_1.3.1 code_1/3.1_shaders_uniform.cpp src/glad.c)
add_executable(learn_opengl_1.3.2 code_1/3.2_shaders_interpolation.cpp src/glad.c)
add_executable(learn_opengl_1.3.3 code_1/3.3_shaders_class.cpp src/glad.c include/learnopengl/shader_s.h)
add_executable(learn_opengl_1.3.4 code_1/3.4_shaders_reserve.cpp src/glad.c include/learnopengl/shader_s.h)
add_executable(learn_opengl_1.3.5 code_1/3.5_shaders_offset.cpp src/glad.c include/learnopengl/shader_s.h)
add_executable(learn_opengl_1.3.6 code_1/3.6_shaders_replace.cpp src/glad.c include/learnopengl/shader_s.h)
add_executable(learn_opengl_1.4.1 code_1/4.1_textures.cpp src/glad.c include/learnopengl/shader_s.h
        include/stb_image.h include/stb_image.cpp)
add_executable(learn_opengl_1.4.2 code_1/4.2_textures_combined.cpp src/glad.c include/learnopengl/shader_s.h
        include/stb_image.h include/stb_image.cpp)
add_executable(learn_opengl_1.4.3 code_1/4.3_textures_reverse.cpp src/glad.c include/learnopengl/shader_s.h
        include/stb_image.h include/stb_image.cpp)
add_executable(learn_opengl_1.4.4 code_1/4.4_textures_exercise2.cpp src/glad.c include/learnopengl/shader_s.h
        include/stb_image.h include/stb_image.cpp)
add_executable(learn_opengl_1.4.5 code_1/4.5_textures_exercise3.cpp src/glad.c include/learnopengl/shader_s.h
        include/stb_image.h include/stb_image.cpp)
add_executable(learn_opengl_1.4.6 code_1/4.6_textures_exercise4.cpp src/glad.c include/learnopengl/shader_s.h
        include/stb_image.h include/stb_image.cpp)
add_executable(learn_opengl_1.5.1 code_1/5.1_transformations.cpp src/glad.c include/learnopengl/shader_s.h
        include/stb_image.h include/stb_image.cpp)
add_executable(learn_opengl_1.5.2 code_1/5.2_transformations_exercise.cpp src/glad.c include/learnopengl/shader_s.h
        include/stb_image.h include/stb_image.cpp)
add_executable(learn_opengl_1.6.1 code_1/6.1_coordinate_systems.cpp src/glad.c include/learnopengl/shader_s.h
        include/stb_image.h include/stb_image.cpp)
add_executable(learn_opengl_1.6.2 code_1/6.2_coordinate_systems_depth.cpp src/glad.c include/learnopengl/shader_s.h
        include/stb_image.h include/stb_image.cpp)
add_executable(learn_opengl_1.6.3 code_1/6.3_coordinate_systems_multiple.cpp  src/glad.c include/learnopengl/shader_s.h
        include/stb_image.h include/stb_image.cpp)
add_executable(learn_opengl_1.7.1 code_1/7.1_camera_circle.cpp  src/glad.c include/learnopengl/shader_s.h
        include/stb_image.h include/stb_image.cpp)
add_executable(learn_opengl_1.7.2 code_1/7.2_camera_keyboard_dt.cpp  src/glad.c include/learnopengl/shader_s.h
        include/stb_image.h include/stb_image.cpp)
add_executable(learn_opengl_1.7.3 code_1/7.3_camera_mouse.cpp  src/glad.c include/learnopengl/shader_s.h
        include/stb_image.h include/stb_image.cpp)

add_executable(learn_opengl_2.1 code_2/1_colors.cpp src/glad.c include/learnopengl/shader_s.h
        include/learnopengl/camera.h include/stb_image.h include/stb_image.cpp)
add_executable(learn_opengl_2.2.1 code_2/2.1_basic_lighting_diffuse.cpp src/glad.c include/learnopengl/shader_s.h
        include/learnopengl/camera.h include/stb_image.h include/stb_image.cpp)

target_link_libraries(learn_opengl_1.1 libglfw3.a)
target_link_libraries(learn_opengl_1.2.1 libglfw3.a)
target_link_libraries(learn_opengl_1.2.2 libglfw3.a)
target_link_libraries(learn_opengl_1.2.3 libglfw3.a)
target_link_libraries(learn_opengl_1.2.4 libglfw3.a)
target_link_libraries(learn_opengl_1.2.5 libglfw3.a)
target_link_libraries(learn_opengl_1.3.1 libglfw3.a)
target_link_libraries(learn_opengl_1.3.2 libglfw3.a)
target_link_libraries(learn_opengl_1.3.3 libglfw3.a)
target_link_libraries(learn_opengl_1.3.4 libglfw3.a)
target_link_libraries(learn_opengl_1.3.5 libglfw3.a)
target_link_libraries(learn_opengl_1.3.6 libglfw3.a)
target_link_libraries(learn_opengl_1.4.1 libglfw3.a)
target_link_libraries(learn_opengl_1.4.2 libglfw3.a)
target_link_libraries(learn_opengl_1.4.3 libglfw3.a)
target_link_libraries(learn_opengl_1.4.4 libglfw3.a)
target_link_libraries(learn_opengl_1.4.5 libglfw3.a)
target_link_libraries(learn_opengl_1.4.6 libglfw3.a)
target_link_libraries(learn_opengl_1.5.1 libglfw3.a)
target_link_libraries(learn_opengl_1.5.2 libglfw3.a)
target_link_libraries(learn_opengl_1.6.1 libglfw3.a)
target_link_libraries(learn_opengl_1.6.2 libglfw3.a)
target_link_libraries(learn_opengl_1.6.3 libglfw3.a)
target_link_libraries(learn_opengl_1.7.1 libglfw3.a)
target_link_libraries(learn_opengl_1.7.2 libglfw3.a)
target_link_libraries(learn_opengl_1.7.3 libglfw3.a)

target_link_libraries(learn_opengl_2.1 libglfw3.a)
target_link_libraries(learn_opengl_2.2.1 libglfw3.a)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)