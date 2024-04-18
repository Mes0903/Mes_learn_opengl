add_executable(
  uniform
  ${CMAKE_CURRENT_SOURCE_DIR}/uniform.cpp
)

target_include_directories(
  uniform
  PRIVATE
    ${THIRD_DIR}/imgui
    ${THIRD_DIR}/implot
    ${THIRD_DIR}/glfw/include
    ${THIRD_DIR}/glad/include
    ${OPENGL_INCLUDE_DIRS}
)

target_link_libraries(
  uniform
  IMGUI_LIB
  IMPLOT_LIB
  glfw
  glad
  ${OPENGL_LIBRARIES}
)

add_executable(
  rgb
  ${CMAKE_CURRENT_SOURCE_DIR}/rgb.cpp
)

target_include_directories(
  rgb
  PRIVATE
    ${THIRD_DIR}/imgui
    ${THIRD_DIR}/implot
    ${THIRD_DIR}/glfw/include
    ${THIRD_DIR}/glad/include
    ${OPENGL_INCLUDE_DIRS}
)

target_link_libraries(
  rgb
  IMGUI_LIB
  IMPLOT_LIB
  glfw
  glad
  ${OPENGL_LIBRARIES}
)

add_executable(
  read_shader
  ${CMAKE_CURRENT_SOURCE_DIR}/read_shader.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/header/src/shader.cpp
)

target_include_directories(
  read_shader
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/header/include
    ${THIRD_DIR}/imgui
    ${THIRD_DIR}/implot
    ${THIRD_DIR}/glfw/include
    ${THIRD_DIR}/glad/include
    ${OPENGL_INCLUDE_DIRS}
)

target_link_libraries(
  read_shader
  IMGUI_LIB
  IMPLOT_LIB
  glfw
  glad
  ${OPENGL_LIBRARIES}
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/shader_code/shader.vert DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/shader_code/shader.frag DESTINATION ${CMAKE_CURRENT_BINARY_DIR})