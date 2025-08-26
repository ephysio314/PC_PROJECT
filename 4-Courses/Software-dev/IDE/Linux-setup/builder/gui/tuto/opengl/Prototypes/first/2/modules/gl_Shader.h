
#include <stdio.h> /* printf */
#include <stdlib.h> /* exit */
#include <stdbool.h>

/*
~CONFIG-SHADER
*/

int conf_shader_SetModule(int _module_id);
int conf_shader_GetModuleMax(void);

struct ConfShader{
	const char * vertex_src;
	const char * fragment_src;
	const float * vertices;
	const int vertex_len;
	const unsigned int * indices;
	const int indices_len;
};

struct ConfShader GetConfShader(void);

/*
~CREATE-SHADER
*/

struct Shader{
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int program;
};

int creat_shader_SetModule(int _module_id);
int creat_shader_GetModuleMax(void);

struct Shader CreateShader(struct ConfShader _conf);

int creat_shader_GetVertexLen(void);
bool creat_shader_IsAbleEAB(void);

/*
~DRAW
*/

int shader_draw_SetModule(int _module_id);
int shader_draw_GetModuleMax(void);

void ShaderDraw(struct Shader _val);

/*
~GENERAL
*/

void DestroyShader(struct Shader _val);

