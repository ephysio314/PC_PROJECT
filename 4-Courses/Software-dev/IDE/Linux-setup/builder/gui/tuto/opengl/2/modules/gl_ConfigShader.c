
#include "gl_Shader.h"

#include <stddef.h>

#include <glad/gl.h>

enum e_module{
	E_NULL,
	
	E_ONE,
	
	E_MAX
};

static enum e_module module_id = 0;

int conf_shader_SetModule(int _module_id){
	if(_module_id < E_MAX){ module_id = _module_id; }
}
int conf_shader_GetModuleMax(void){
	return (int)E_MAX;
}

/* Interface: module one */

const char * one_GetShaderVertexSrc(void);
const char * one_GetShaderFragmentSrc(void);
float * one_GetVertices(void);
int one_GetVerticesLen(void);

/*
~CORE
*/

const char * conf_shader_GetShaderVertexSrc(void){
	switch(module_id){
		case E_NULL: /* No module specified. Default */
			return one_GetShaderVertexSrc();
			break;
	
		case E_ONE: /* Default module specified */
			return one_GetShaderVertexSrc();
			break;
	
		default:
			break;
	}
	return "\0";
}

const char * conf_shader_GetShaderFragmentSrc(void){
	switch(module_id){
		case E_NULL: /* No module specified. Default */
			return one_GetShaderFragmentSrc();
			break;
	
		case E_ONE: /* Default module specified */
			return one_GetShaderFragmentSrc();
			break;
	
		default:
			break;
	}
	return "\0";
}

float * conf_shader_GetVertices(void){
	switch(module_id){
		case E_NULL: /* No module specified. Default */
			return one_GetVertices();
			break;
	
		case E_ONE: /* Default module specified */
			return one_GetVertices();
			break;
	
		default:
			break;
	}
	return NULL;
}

int conf_shader_GetVerticesLen(void){
	switch(module_id){
		case E_NULL: /* No module specified. Default */
			return one_GetVerticesLen();
			break;
	
		case E_ONE: /* Default module specified */
			return one_GetVerticesLen();
			break;
	
		default:
			break;
	}
	return 0;
}

/*
~MODULE-ONE
*/

static const char *shader_vertex_src = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
static const char *shader_fragment_src = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

#define VERTICES_LEN 9
static float vertices[VERTICES_LEN] = {
	-0.5f, -0.5f, 0.0f, // left  
	0.5f, -0.5f, 0.0f, // right 
	0.0f,  0.5f, 0.0f  // top   
}; 

const char * one_GetShaderVertexSrc(void){
	return shader_vertex_src;
}
const char * one_GetShaderFragmentSrc(void){
	return shader_fragment_src;
}
float * one_GetVertices(void){
	return vertices;
}
int one_GetVerticesLen(void){
	return VERTICES_LEN;
}


