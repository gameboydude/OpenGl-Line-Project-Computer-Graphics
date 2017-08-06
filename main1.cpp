#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <glfw/glfw3.h>


using namespace std;

const GLint WIDTH = 800, HEIGHT = 600;

int main(void)
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow *window = glfCreateWindow(WIDTH, HEIGHT, "Ben Strong OpenGL");

    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

    if(nullptr==window)
    {
        std::cout<< "Failed to create GLFW window" << std::endl;
        glfwTerminate();

        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    if (GLEW_OK != glewInit())
    {
        std::cout<<"Failed to make glew happen"<< std::endl;
        return EXIT_FAILURE;
    }

    glViewport(0,0,screenWidth, screenHeight);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        //glClearColor(); can be used with new colored background
        glClear(GL_COLOR_BUFFER_BIT);

        //drawing

        glfwSwapBuffers(window);

    }

    glfwTerminate();

    return EXIT_SUCCESS;
}
