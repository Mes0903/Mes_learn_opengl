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