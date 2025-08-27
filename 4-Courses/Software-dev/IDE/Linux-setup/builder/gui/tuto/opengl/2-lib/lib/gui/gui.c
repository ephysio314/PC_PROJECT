
#include "gui.h"

#include <stdio.h>
#include <stdlib.h>

static char title[50] = "Title";
static int win_width = 320;
static int win_height = 320;

static void error_callback(int error, const char* description){
    fprintf(stderr, "Error: %s\n", description);
}

struct GuiConf gui_CreateConf(void){

  glfwSetErrorCallback(error_callback);

  if (!glfwInit()){
    exit(EXIT_FAILURE);
  }

	GLFWwindow* win = glfwCreateWindow(win_width, win_height, title, NULL, NULL);

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

void gui_DestroyConf(struct GuiConf _val){
	glfwDestroyWindow(_val.win);
  glfwTerminate();
}

bool gui_AskClose(struct GuiConf _v){
	bool v = glfwWindowShouldClose(_v.win);
	return v;
}

