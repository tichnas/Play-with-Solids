#include "main.h"

#ifndef BALL_H
#define BALL_H

class Ball {
 public:
  Ball() {}
  Ball(float x, float y, color_t color);
  glm::vec3 position;
  float rotation;
  void draw(glm::mat4 VP, int index);
  void set_position(float x, float y);
  void translate(float x, float y, float z);
  void tick();
  double speed;

 private:
  VAO *object0;
  VAO *object1;
  VAO *object2;
  VAO *object3;
};

#endif  // BALL_H
