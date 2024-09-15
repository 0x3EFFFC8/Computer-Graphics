cmake_minimum_required(VERSION 3.28.5)

project(OPENGL3 VERSION 0.1.0 LANGUAGES CXX)

cmake_policy(SET CMP0072 NEW)

set(CMAKE_BUILD_TYPE Debug) 
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic -g -fdiagnostics-color=always -fdiagnostics-show-option")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra -pedantic -O3 -fdiagnostics-color=always -fdiagnostics-show-option")
set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED) 
find_package(GLUT REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(X11 REQUIRED)

include_directories(cwc/include freeglut/include glew/include freeglut/include glm /usr/include /usr/include/FreeImage)
link_directories(/usr/lib64)

file(GLOB_RECURSE SOURCES
    "cwc/source/*.cpp"
    "glew/source/*.c"
    "freeglut/source/*.c"
    glm/glm.cpp
    myWindow.cpp
    myApplication.cpp
    ModelTextureRenderer.cpp
    World.cpp
    Natural.cpp 
    Artificial.cpp  
    main.cpp
)

add_executable(OPENGL3 ${SOURCES})

target_link_libraries(OPENGL3 PRIVATE 
  glm::glm 
  OpenGL::GL
  OpenGL::GLU
  GLEW::GLEW
  GLUT::GLUT
  X11 
  /usr/lib64/libfreeimage.so
)