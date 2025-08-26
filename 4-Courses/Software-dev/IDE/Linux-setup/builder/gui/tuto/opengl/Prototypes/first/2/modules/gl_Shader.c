
#include "gl_Shader.h"

#include <glad/gl.h>

void DestroyShader(struct Shader _val){
	glDeleteVertexArrays(1, &_val.VAO);
  glDeleteBuffers(1, &_val.VBO);
  glDeleteBuffers(1, &_val.EBO);
  glDeleteProgram(_val.program);
}


