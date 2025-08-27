
#include <stdio.h>
#include <stdlib.h> /* exit, calloc, free */
#include <stdbool.h>

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

/*
~CONFIG-GUI
*/

#define WIN_WIDTH 320
#define WIN_HEIGHT 320

struct GuiConf{
	GLFWwindow* win;
};

static void error_callback(int error, const char* description){
    fprintf(stderr, "Error: %s\n", description);
}

struct GuiConf CreateGuiConf(void){

  glfwSetErrorCallback(error_callback);

  if (!glfwInit()){
    exit(EXIT_FAILURE);
  }

	GLFWwindow* win = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "glfw", NULL, NULL);

  if (!win){
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(win);
  gladLoadGL(glfwGetProcAddress);
  glfwSwapInterval(1);

	struct GuiConf return_val = {
		win
	};
	return return_val;
}

/*
~INTERFACE-MODE-IDENTIFIER: SHADER
*/

enum e_mode_shader{
	E_MODE_SHADER_NULL,
	
	E_MODE_SHADER_ONE,
	E_MODE_SHADER_TWO,
	
	E_MODE_SHADER_MAX
};

enum e_modules_shader{
	E_MODULES_NULL,
	
	E_MODULES_SET_CONF,
	E_MODULES_LOAD_SHADER,
	E_MODULES_DRAW_SHADER,
	
	E_MODULES_MAX
};

static enum e_mode_shader shader_mode=0;
static enum e_mode_shader shader_module=0;

bool shader_IsAbleMode(enum e_mode_shader _v){
	return (bool)(0 < _v && _v < E_MODULES_MAX);
}
void shader_SetMode(enum e_mode_shader _v){
	if(shader_IsAbleMode(_v)){ shader_mode = _v; }
}

bool shader_IsAbleModule(enum e_modules_shader _v){
	return (bool)(0 < _v && _v < E_MODULES_MAX);
}
void shader_SetModule(enum e_modules_shader _v){
	if(shader_IsAbleModule(_v)){ shader_module = _v; }
}

/*
~INTERFACE-MODE-OBJECT: SHADER
*/

struct ShaderConf{
	char * vertex_src;
	char * fragment_src;
	float * vertices;
	int vertex_len;
	unsigned int * indices;
	int indices_len;
};

struct ShaderObject{
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	bool is_able_EBO;
};

struct Shader{
	unsigned int program;
	struct ShaderObject obj;
};

/*
~INTERFACE-CALL: SHADER
*/

static struct ShaderConf * shader_conf_buf = NULL;
static struct Shader shader_buf = (struct Shader){0};

void shader_DestroyConf(void);

void shader_CreateConf(void){
	if(NULL == shader_conf_buf){
		shader_conf_buf = (struct ShaderConf *)malloc(sizeof(struct ShaderConf));
	}
}
void shader_DestroyConf(void){
	if(NULL != shader_conf_buf){ free(shader_conf_buf); shader_conf_buf=NULL;  }
}

struct ShaderConf * one_CreateShaderConf(void);

struct Shader CreateShader(struct ShaderConf _v);

void one_DrawShader(struct Shader _v);
void two_DrawShader(struct Shader _v);

void shader_SetConf(void){
	shader_DestroyConf();
	switch(shader_mode){
		case E_MODE_SHADER_ONE:
			shader_conf_buf = one_CreateShaderConf();
			break;
		case E_MODE_SHADER_TWO:
			shader_conf_buf = one_CreateShaderConf();
			break;
	}
}

void shader_Load(void){
	if(NULL == shader_conf_buf){ shader_SetConf(); }
	switch(shader_mode){
		case E_MODE_SHADER_ONE:
			shader_buf = CreateShader(*shader_conf_buf);
			break;
		case E_MODE_SHADER_TWO:
			shader_buf = CreateShader(*shader_conf_buf);
			break;
	}
}

void shader_Draw(void){
	switch(shader_mode){
		case E_MODE_SHADER_ONE:
			one_DrawShader(shader_buf);
			break;
		case E_MODE_SHADER_TWO:
			one_DrawShader(shader_buf);
			break;
	}
}

void shader_Start(void){
	shader_mode=1;
	shader_module=0;
	shader_CreateConf();
}
void shader_Terminate(void){
	shader_mode=0;
	shader_module=0;
	shader_DestroyConf();
}

void shader_Proc(enum e_modules_shader _v){
	switch(_v){
		case E_MODULES_NULL: /* Do nothing */
			break;
	
		case E_MODULES_SET_CONF:
			shader_SetConf();
			break;
	
		case E_MODULES_LOAD_SHADER:
			shader_Load();
			break;
			
		case E_MODULES_DRAW_SHADER:
			shader_Draw();
			break;
		
		default:
			/* Fail to find the module */
			break;
	}
}

/*
~INTERFACE-VALUE-MODULES: SHADER
*/

/*
~Moduel one
*/

static char one_shader_vertex_src[255] = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
static char one_shader_fragment_src[255] = "#version 330 core\n"
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

#define one_INDICES_LEN 3
static unsigned int one_indices[one_INDICES_LEN] = {
	0, 1, 2
};

struct ShaderConf * one_CreateShaderConf(void){
	
	struct ShaderConf v = (struct ShaderConf){ 
		one_shader_vertex_src,
		one_shader_fragment_src,
		one_vertices,
		one_VERTICES_LEN,
		one_indices,
		one_INDICES_LEN
	};
	
	struct ShaderConf * vp = (struct ShaderConf *)malloc(sizeof(struct ShaderConf));
	(*vp) = v;
	
	return (struct ShaderConf*)vp;
}

/*
~Moduel two
*/

int two_GetShaderConfVertexLen(void){
	return one_VERTICES_LEN;
}

/*
~CREATE-SHADER
*/

unsigned int CreateShaderProgram(const char * _vertex_src, const char * _fragment_src){
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &_vertex_src, NULL);
  glCompileShader(vertexShader);
  
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &_fragment_src, NULL);
  glCompileShader(fragmentShader);
  
  unsigned int shader_program = glCreateProgram();
  glAttachShader(shader_program, vertexShader);
  glAttachShader(shader_program, fragmentShader);
  glLinkProgram(shader_program);
  
  return shader_program;
}

struct ShaderObject CreateShaderObject( const float * _vertices, const int _vertice_len, const unsigned * _indices, const int _indices_len ){
  unsigned int VBO, VAO, EBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);
    
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * _vertice_len, _vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * _indices_len, _indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0); 

  glBindVertexArray(0);  
 
  struct ShaderObject v = {
		VAO,
		VBO,
		EBO
  };
  return v;
}

struct Shader CreateShader(struct ShaderConf _v){

	struct Shader v = {
		CreateShaderProgram( _v.vertex_src, _v.fragment_src ),
		CreateShaderObject( _v.vertices, _v.vertex_len, _v.indices, _v.indices_len )
	};
	return v;
}

/*
~PROCESS
*/

void one_DrawShader(struct Shader _v){
	glUseProgram(_v.program);
	glBindVertexArray(_v.obj.VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void two_DrawShader(struct Shader _v){
	glUseProgram(_v.program);
	glBindVertexArray(_v.obj.VAO);
	glDrawElements(GL_TRIANGLES, two_GetShaderConfVertexLen(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

/*
~General
*/

void DestroyShader(struct Shader _v){
	glDeleteVertexArrays(1, &_v.obj.VAO);
  glDeleteBuffers(1, &_v.obj.VBO);
  glDeleteBuffers(1, &_v.obj.EBO);
  glDeleteProgram(_v.program);
}

/*
~MAIN
*/

int main(void){
  struct GuiConf gui_conf = CreateGuiConf();
  
  shader_SetMode(1);
  
  /*
	E_MODULES_SET_CONF
	E_MODULES_LOAD_SHADER
	E_MODULES_DRAW_SHADER
  */
  
  shader_Start();
  
  shader_Proc(E_MODULES_SET_CONF);
  shader_Proc(E_MODULES_LOAD_SHADER);

  while(!glfwWindowShouldClose(gui_conf.win)){
    glClearColor(0.5f, 0.7f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
  	shader_Proc(E_MODULES_DRAW_SHADER);
    
    glfwSwapBuffers(gui_conf.win);
    
    glfwWaitEvents();
  }

	glfwDestroyWindow(gui_conf.win);
  glfwTerminate();
  shader_Terminate();
  return 0;
}

