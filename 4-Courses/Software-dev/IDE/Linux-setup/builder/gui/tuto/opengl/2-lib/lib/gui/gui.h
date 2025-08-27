
#include <stdbool.h>

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

struct GuiConf{
	GLFWwindow* win;
};

struct GuiConf gui_CreateConf(void);
void gui_DestroyConf(struct GuiConf _conf);

bool gui_AskClose(struct GuiConf _v);

