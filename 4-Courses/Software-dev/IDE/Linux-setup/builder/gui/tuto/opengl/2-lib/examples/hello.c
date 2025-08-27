
#include <gui/gui.h>

int main(void){
  struct GuiConf gui_conf = gui_CreateConf();

  while(!gui_AskClose(gui_conf)){
    glClearColor(0.5f, 0.7f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(gui_conf.win);
    glfwWaitEvents();
  }

	gui_DestroyConf(gui_conf);
  return 0;
}

