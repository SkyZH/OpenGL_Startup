#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/glew.h>

#include "GLTestConfig.h"

void error_callback(int error, const char* description) {
  std::cerr << "Error: " << description << std::endl;
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GLFW_TRUE);
}
const int width = 1920, height = 1080;

class GLTest {
private:
  GLFWwindow* window;
public:
  GLTest(GLFWwindow* window) {
    this->window = window;
  }

  int render() {
    glfwSwapBuffers(this->window);
    glfwPollEvents();
    return 0;
  }
};

int main() {
  if (!glfwInit())
  {
    return 0;
  }
  GLFWwindow* window = glfwCreateWindow(width, height, "GLTest", NULL, NULL);
  if (!window)
  {
    return 0;
  }
  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window, key_callback);
  glfwSwapInterval(1);
  auto ctx = new GLTest(window);
  while (!glfwWindowShouldClose(window))
  {
    ctx->render();
  }
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
