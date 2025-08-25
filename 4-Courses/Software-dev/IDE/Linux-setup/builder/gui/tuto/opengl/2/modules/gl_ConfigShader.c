
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

struct ConfShader one_GetConfShader(void);

/*
~CORE
*/

struct ConfShader GetConfShader(void){
	struct ConfShader return_val;
	switch(module_id){
		case E_NULL: /* No module specified. Default */
			return one_GetConfShader();
			break;
	
		case E_ONE: /* Default module specified */
			return one_GetConfShader();
			break;
	
		default:
			break;
	}
	return return_val;
}

/*
~MODULE-ONE
*/

static const char *one_shader_vertex_src = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
static const char *one_shader_fragment_src = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

#define one_VERTICES_LEN 9
static float one_vertices[one_VERTICES_LEN] = {
	-0.5f, -0.5f, 0.0f, // left  
	0.5f, -0.5f, 0.0f, // right 
	0.0f,  0.5f, 0.0f  // top   
}; 

struct ConfShader one_GetConfShader(void){
	return (struct ConfShader){ 
		one_shader_vertex_src,
		one_shader_fragment_src,
		one_vertices,
		one_VERTICES_LEN
	};
}


