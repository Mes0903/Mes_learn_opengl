#include "shader.h"

#include <glad/glad.h>

#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
  std::string vertexSource;
  std::string fragmentSource;
  std::ifstream vertexFile;
  std::ifstream fragmentFile;

  vertexFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  fragmentFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try {
    vertexFile.open(vertexPath);
    fragmentFile.open(fragmentPath);

    if (!vertexFile.is_open() || !fragmentFile.is_open()) {
      throw std::runtime_error("Failed to open file");
    }

    std::stringstream vertexSS;
    std::stringstream fragmentSS;

    vertexSS << vertexFile.rdbuf();
    fragmentSS << fragmentFile.rdbuf();

    vertexFile.close();
    fragmentFile.close();

    vertexSource = vertexSS.str();
    fragmentSource = fragmentSS.str();
  }
  catch (const std::exception &ex) {
    std::cerr << ex.what() << '\n';
  }

  unsigned int vertexShader, fragmentShader;
  const char *vertexCode = vertexSource.c_str();
  const char *fragmentCode = fragmentSource.c_str();

  // vertex shader
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexCode, NULL);
  glCompileShader(vertexShader);
  checkCompileErrors(vertexShader, "VERTEX");

  // fragment shader
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentCode, NULL);
  glCompileShader(fragmentShader);
  checkCompileErrors(fragmentShader, "FRAGMENT");

  // shader program
  ID = glCreateProgram();
  glAttachShader(ID, vertexShader);
  glAttachShader(ID, fragmentShader);
  glLinkProgram(ID);
  checkCompileErrors(ID, "PROGRAM");

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void Shader::use()
{
  glUseProgram(ID);
}

void Shader::checkCompileErrors(unsigned int shader, std::string type)
{
  int success;
  char infoLog[1024];

  if (type != "PROGRAM") {
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
      glGetShaderInfoLog(shader, 1024, NULL, infoLog);
      std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: "
                << type << '\n'
                << infoLog << '\n';
    }
  }
  else {
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if (!success) {
      glGetProgramInfoLog(shader, 1024, NULL, infoLog);
      std::cerr << "ERROR::PROGRAM_LINKING_ERROR of type: "
                << type << '\n'
                << infoLog << '\n';
    }
  }
}