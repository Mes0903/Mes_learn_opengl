add_executable(
  triangle
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_include_directories(
  triangle
  PRIVATE
    ${THIRD_DIR}/imgui
    ${THIRD_DIR}/implot
    ${THIRD_DIR}/glfw/include
    ${THIRD_DIR}/glad/include
    ${OPENGL_INCLUDE_DIRS}
)

target_link_libraries(
  triangle
  IMGUI_LIB
  IMPLOT_LIB
  glfw
  glad
  ${OPENGL_LIBRARIES}
)