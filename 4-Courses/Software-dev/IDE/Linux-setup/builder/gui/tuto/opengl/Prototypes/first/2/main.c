
/*
~TUTO
*/

#include <gl_Shader.h>

static struct Shader shader = (struct Shader){0};

void Init(void){
	#if 0
	creat_shader_SetModule(2);
	shader_draw_SetModule(2);
	#elif 1
	creat_shader_SetModule(2);
	shader_draw_SetModule(1);
	printf("EAB state: '%d'\n", creat_shader_IsAbleEAB());
	#endif

	shader = CreateShader(GetConfShader());
}

void Quit(void){
	DestroyShader(shader);
}

/*
~MAIN
*/

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

#define WIDTH 320
#define HEIGHT 320

int main(void){

    GLFWwindow* window;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "glfw", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);
    
    Init();

    while (!glfwWindowShouldClose(window))
    {
    		glClearColor(0.5f, 0.7f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        ShaderDraw(shader);
        
        glfwSwapBuffers(window);
        glfwWaitEvents();
    }
    
    Quit();

    glfwTerminate();
    return 0;
}

