#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader {
public:
  Shader(const char *vertexPath, const char *fragmentPath);

public:
  void use();
  unsigned int ID;

private:
  void checkCompileErrors(unsigned int shader, std::string type);
};

#endif