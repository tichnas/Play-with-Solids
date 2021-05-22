#include "main.h"

#include "ball.h"
#include "timer.h"

using namespace std;

GLMatrices Matrices;
GLuint programID;
GLFWwindow *window;

Ball ball1;

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
glm::vec3 eye(7, 7, 7);
glm::vec3 target(0, 0, 0);
glm::vec3 up(0, 1, 0);
int objIndex = 2;

Timer t60(1.0 / 60);

void draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glUseProgram(programID);
  Matrices.view = glm::lookAt(eye, target, up);  // Rotating Camera for 3D
  glm::mat4 VP = Matrices.projection * Matrices.view;
  ball1.draw(VP, objIndex);
}

void tick_input(GLFWwindow *window) {
  glm::vec3 front = target - eye;
  glm::vec3 cam_horizontal = glm::normalize(glm::cross(up, front));
  glm::vec3 cam_vertical = glm::normalize(glm::cross(front, cam_horizontal));

  if (glfwGetKey(window, GLFW_KEY_0))
    objIndex = 0;
  if (glfwGetKey(window, GLFW_KEY_1))
    objIndex = 1;
  if (glfwGetKey(window, GLFW_KEY_2))
    objIndex = 2;
  if (glfwGetKey(window, GLFW_KEY_3))
    objIndex = 3;

  if (glfwGetKey(window, GLFW_KEY_Q)) {
    eye += 0.1f * front;
  }
  if (glfwGetKey(window, GLFW_KEY_W)) {
    eye -= 0.1f * front;
  }
  if (glfwGetKey(window, GLFW_KEY_E)) {
    eye -= cam_horizontal * 0.1f;
    target -= cam_horizontal * 0.1f;
  }
  if (glfwGetKey(window, GLFW_KEY_R)) {
    eye += cam_horizontal * 0.1f;
    target += cam_horizontal * 0.1f;
  }
  if (glfwGetKey(window, GLFW_KEY_T)) {
    eye += cam_vertical * 0.1f;
    target += cam_vertical * 0.1f;
  }
  if (glfwGetKey(window, GLFW_KEY_Y)) {
    eye -= cam_vertical * 0.1f;
    target -= cam_vertical * 0.1f;
  }

  if (glfwGetKey(window, GLFW_KEY_A)) ball1.translate(-0.1, 0, 0);
  if (glfwGetKey(window, GLFW_KEY_S)) ball1.translate(0.1, 0, 0);
  if (glfwGetKey(window, GLFW_KEY_D)) ball1.translate(0, -0.1, 0);
  if (glfwGetKey(window, GLFW_KEY_F)) ball1.translate(0, 0.1, 0);
  if (glfwGetKey(window, GLFW_KEY_G)) ball1.translate(0, 0, -0.1);
  if (glfwGetKey(window, GLFW_KEY_H)) ball1.translate(0, 0, 0.1);

  if (glfwGetKey(window, GLFW_KEY_Z)) {
    target = ball1.position;
    eye = glm::vec3(10,0,0);
  }
  if (glfwGetKey(window, GLFW_KEY_X)) {
    target = ball1.position;
    eye = glm::vec3(0,3,10);
  }
  if (glfwGetKey(window, GLFW_KEY_C)) {
    target = ball1.position;
    eye = glm::vec3(10,10,0);
  }

  if (glfwGetKey(window, GLFW_KEY_N)) {
    ball1.rotation += 1;
  }
  if (glfwGetKey(window, GLFW_KEY_M)) {
    target = ball1.position;
    glm::mat4 rotMat = glm::rotate(0.01f, cam_vertical);
    eye = glm::translate(ball1.position) * rotMat * glm::translate(-ball1.position) * glm::vec4(eye, 1.0f);
  }

}

void tick_elements() {
  ball1.tick();
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
  /* Objects should be created before any other gl function and shaders */
  // Create the models

  ball1 = Ball(0, 0, COLOR_GREEN);

  // Create and compile our GLSL program from the shaders
  programID = LoadShaders("../source/shaders/shader.vert",
                          "../source/shaders/shader.frag");
  // Get a handle for our "MVP" uniform
  Matrices.MatrixID = glGetUniformLocation(programID, "MVP");

  reshapeWindow(window, width, height);

  // Background color of the scene
  glClearColor(COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0,
               COLOR_BACKGROUND.b / 256.0, 0.0f);  // R, G, B, A
  glClearDepth(1.0f);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);

  cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
  cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
  cout << "VERSION: " << glGetString(GL_VERSION) << endl;
  cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}

int main(int argc, char **argv) {
  srand(time(0));
  int width = 600;
  int height = 600;

  window = initGLFW(width, height);

  initGL(window, width, height);

  /* Draw in loop */
  while (!glfwWindowShouldClose(window)) {
    // Process timers

    if (t60.processTick()) {
      // 60 fps
      // OpenGL Draw commands
      draw();
      // Swap Frame Buffer in double buffering
      glfwSwapBuffers(window);

      tick_elements();
      tick_input(window);
    }

    // Poll for Keyboard and mouse events
    glfwPollEvents();
  }

  quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
  return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
         (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
  float top = screen_center_y + 4 / screen_zoom;
  float bottom = screen_center_y - 4 / screen_zoom;
  float left = screen_center_x - 4 / screen_zoom;
  float right = screen_center_x + 4 / screen_zoom;
  Matrices.projection =
      glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 500.0f);
}
