
#include "gl_Shader.h"

#include <glad/gl.h>

void DestroyShader(struct Shader _val){
	glDeleteVertexArrays(1, &_val.VAO);
  glDeleteBuffers(1, &_val.VBO);
  glDeleteProgram(_val.program);
}

void Draw(struct Shader _val){
	glUseProgram(_val.program);
	glBindVertexArray(_val.VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_TRIANGLES, 0, 3);
}


