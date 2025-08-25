
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
};

struct ConfShader GetConfShader(void);

/*
~CREATE-SHADER
*/

struct Shader{
	unsigned int VAO;
	unsigned int VBO;
	unsigned int program;
};

int creat_shader_GetModuleMax(void);

struct Shader CreateShader(struct ConfShader _conf);

/*
~GENERAL
*/

void DestroyShader(struct Shader _val);

void Draw(struct Shader _val);

