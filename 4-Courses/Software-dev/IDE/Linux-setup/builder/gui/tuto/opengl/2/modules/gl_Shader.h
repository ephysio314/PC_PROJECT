
/*
~CONFIG-SHADER
*/

int conf_shader_SetModule(int _module_id);
int conf_shader_GetModuleMax(void);

const char * conf_shader_GetShaderVertexSrc(void);
const char * conf_shader_GetShaderFragmentSrc(void);
float * conf_shader_GetVertices(void);
int conf_shader_GetVerticesLen(void);

struct ConfShader{
	const char * vertex_src;
	const char * fragment_src;
	float * vertices;
	int vertex_len;
};

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

