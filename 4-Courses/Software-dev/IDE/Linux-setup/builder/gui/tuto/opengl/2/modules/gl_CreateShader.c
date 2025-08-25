
#include "gl_Shader.h"

#include <stddef.h>

#include <glad/gl.h>

enum e_module{
	E_NULL,
	
	E_ONE,
	
	E_MAX
};

/* Interface: module one */

struct Shader one_CreateShader(struct ConfShader _conf);

/*
~CORE
*/

static enum e_module module_id = 0;

int creat_shader_SetModule(int _module_id){
	if(_module_id < E_MAX){ module_id = _module_id; }
}
int creat_shader_GetModuleMax(void){
	return (int)E_MAX;
}

struct Shader CreateShader(struct ConfShader _conf){
	struct Shader return_val = (struct Shader){0};
	switch(module_id){
		case E_NULL: /* No module specified. Default */
			return_val = one_CreateShader(_conf);
			break;
	
		case E_ONE: /* Default module specified */
			return_val = one_CreateShader(_conf);
			break;
	
		default:
			break;
	}
	return return_val;
}

/*
~MODULE-ONE
*/

struct Shader one_CreateShader(struct ConfShader _conf){
	struct Shader return_val = (struct Shader){0};
	
	/* SHADER-PROGRAM */
	
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &_conf.vertex_src, NULL);
  glCompileShader(vertexShader);
  
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &_conf.fragment_src, NULL);
  glCompileShader(fragmentShader);
  
  unsigned int shader_program = glCreateProgram();
  glAttachShader(shader_program, vertexShader);
  glAttachShader(shader_program, fragmentShader);
  glLinkProgram(shader_program);
  
  return_val.program = shader_program;
  
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
  
  /* OBJECTS */
  
  unsigned int VBO, VAO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * _conf.vertex_len, _conf.vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0); 
  glBindVertexArray(0); 
  
  return_val.VBO = VBO;
  return_val.VAO = VAO;
    
	return return_val;
}

