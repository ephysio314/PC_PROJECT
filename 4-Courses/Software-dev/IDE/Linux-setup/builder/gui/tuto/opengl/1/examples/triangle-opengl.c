
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

struct Shader{
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int program;
};



/*
~MAIN
*/

int main(void){
  struct GuiConf gui_conf = CreateGuiConf();

  while(!glfwWindowShouldClose(gui_conf.win)){
    glClearColor(0.5f, 0.7f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(gui_conf.win);
    glfwWaitEvents();
  }

	glfwDestroyWindow(gui_conf.win);
  glfwTerminate();
  return 0;
}

