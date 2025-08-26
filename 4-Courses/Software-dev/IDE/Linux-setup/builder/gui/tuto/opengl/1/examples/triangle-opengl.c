
#include <stdio.h>
#include <stdlib.h>

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
~SHADER
*/

struct ShaderConf{
	const char * vertex_src;
	const char * fragment_src;
	const float * vertices;
	const int vertex_len;
	const unsigned int * indices;
	const int indices_len;
};

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

#define one_INDICES_LEN 3
static unsigned int one_indices[one_INDICES_LEN] = {
	0, 1, 2
}; 

struct ShaderConf one_CreateShaderConf(void){
	return (struct ShaderConf){ 
		one_shader_vertex_src,
		one_shader_fragment_src,
		one_vertices,
		one_VERTICES_LEN,
		one_indices,
		one_INDICES_LEN
	};
}

struct ShaderObject{
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
};

struct Shader{
	unsigned int program;
	struct ShaderObject obj;
};

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
  
  struct Shader shader = CreateShader(one_CreateShaderConf());

  while(!glfwWindowShouldClose(gui_conf.win)){
    glClearColor(0.5f, 0.7f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    one_DrawShader(shader);
    
    glfwSwapBuffers(gui_conf.win);
    
    glfwWaitEvents();
  }

	glfwDestroyWindow(gui_conf.win);
  glfwTerminate();
  return 0;
}

