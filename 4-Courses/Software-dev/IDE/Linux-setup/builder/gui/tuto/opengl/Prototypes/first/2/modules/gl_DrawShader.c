
#include "gl_Shader.h"

#include <glad/gl.h>

enum e_module{
	E_NULL,
	
	E_ONE,
	E_TWO,
	
	E_MAX
};

/* Interface: */

void one_ShaderDraw(struct Shader _val);

void two_ShaderDraw(struct Shader _val);

/*
~CORE
*/

static enum e_module module_id = 0;

int shader_draw_SetModule(int _module_id){
	if(_module_id < E_MAX){ module_id = _module_id; }
}
int shader_draw_GetModuleMax(void){
	return (int)E_MAX;
}

void ShaderDraw(struct Shader _val){
	switch(module_id){
		case E_NULL: /* No module specified. Default */
			one_ShaderDraw(_val);
			break;
	
		case E_ONE: /* Default module specified */
			one_ShaderDraw(_val);
			break;
	
		case E_TWO:
			two_ShaderDraw(_val);
			break;
	
		default:
			break;
	}
}

/*
~ONE
*/

void one_ShaderDraw(struct Shader _val){
	glUseProgram(_val.program);
	glBindVertexArray(_val.VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

/*
~TWO
*/

void two_ShaderDraw(struct Shader _val){
	if(!creat_shader_IsAbleEAB()){ printf("ERROR:\n- Try to use glDrawElements when creat_shader_IsAbleEAB was false.\n");exit(1); }
	glUseProgram(_val.program);
	glBindVertexArray(_val.VAO);
	glDrawElements(GL_TRIANGLES, creat_shader_GetVertexLen(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

