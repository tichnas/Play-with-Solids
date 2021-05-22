#include "ball.h"

#include "main.h"

Ball::Ball(float x, float y, color_t color) {
  this->position = glm::vec3(x, y, 0);
  this->rotation = 0;
  speed = 1;

  static const GLfloat vertex_buffer_data3[] = {
      0, 0, 1,  sin(M_PI * 0 / 180),   cos(M_PI * 0 / 180),   0, sin(M_PI * 60 / 180),  cos(M_PI * 60 / 180),  0,
      0, 0, 1,  sin(M_PI * 60 / 180),  cos(M_PI * 60 / 180),  0, sin(M_PI * 120 / 180), cos(M_PI * 120 / 180), 0,
      0, 0, 1,  sin(M_PI * 120 / 180), cos(M_PI * 120 / 180), 0, sin(M_PI * 180 / 180), cos(M_PI * 180 / 180), 0,
      0, 0, 1,  sin(M_PI * 180 / 180), cos(M_PI * 180 / 180), 0, sin(M_PI * 240 / 180), cos(M_PI * 240 / 180), 0,
      0, 0, 1,  sin(M_PI * 240 / 180), cos(M_PI * 240 / 180), 0, sin(M_PI * 300 / 180), cos(M_PI * 300 / 180), 0,
      0, 0, 1,  sin(M_PI * 300 / 180), cos(M_PI * 300 / 180), 0, sin(M_PI * 360 / 180), cos(M_PI * 360 / 180), 0,
      0, 0, -1, sin(M_PI * 0 / 180),   cos(M_PI * 0 / 180),   0, sin(M_PI * 60 / 180),  cos(M_PI * 60 / 180),  0,
      0, 0, -1, sin(M_PI * 60 / 180),  cos(M_PI * 60 / 180),  0, sin(M_PI * 120 / 180), cos(M_PI * 120 / 180), 0,
      0, 0, -1, sin(M_PI * 120 / 180), cos(M_PI * 120 / 180), 0, sin(M_PI * 180 / 180), cos(M_PI * 180 / 180), 0,
      0, 0, -1, sin(M_PI * 180 / 180), cos(M_PI * 180 / 180), 0, sin(M_PI * 240 / 180), cos(M_PI * 240 / 180), 0,
      0, 0, -1, sin(M_PI * 240 / 180), cos(M_PI * 240 / 180), 0, sin(M_PI * 300 / 180), cos(M_PI * 300 / 180), 0,
      0, 0, -1, sin(M_PI * 300 / 180), cos(M_PI * 300 / 180), 0, sin(M_PI * 360 / 180), cos(M_PI * 360 / 180), 0,
  };

  static const GLfloat vertex_buffer_data2[] = {
    0, 0, 1, sin(0 * 2 * M_PI / 11), cos(0 * 2 * M_PI / 11), 0, sin(1 * 2 * M_PI / 11), cos(1 * 2 * M_PI / 11), 0,
    0, 0, 1, sin(1 * 2 * M_PI / 11), cos(1 * 2 * M_PI / 11), 0, sin(2 * 2 * M_PI / 11), cos(2 * 2 * M_PI / 11), 0,
    0, 0, 1, sin(2 * 2 * M_PI / 11), cos(2 * 2 * M_PI / 11), 0, sin(3 * 2 * M_PI / 11), cos(3 * 2 * M_PI / 11), 0,
    0, 0, 1, sin(3 * 2 * M_PI / 11), cos(3 * 2 * M_PI / 11), 0, sin(4 * 2 * M_PI / 11), cos(4 * 2 * M_PI / 11), 0,
    0, 0, 1, sin(4 * 2 * M_PI / 11), cos(4 * 2 * M_PI / 11), 0, sin(5 * 2 * M_PI / 11), cos(5 * 2 * M_PI / 11), 0,
    0, 0, 1, sin(5 * 2 * M_PI / 11), cos(5 * 2 * M_PI / 11), 0, sin(6 * 2 * M_PI / 11), cos(6 * 2 * M_PI / 11), 0,
    0, 0, 1, sin(6 * 2 * M_PI / 11), cos(6 * 2 * M_PI / 11), 0, sin(7 * 2 * M_PI / 11), cos(7 * 2 * M_PI / 11), 0,
    0, 0, 1, sin(7 * 2 * M_PI / 11), cos(7 * 2 * M_PI / 11), 0, sin(8 * 2 * M_PI / 11), cos(8 * 2 * M_PI / 11), 0,
    0, 0, 1, sin(8 * 2 * M_PI / 11), cos(8 * 2 * M_PI / 11), 0, sin(9 * 2 * M_PI / 11), cos(9 * 2 * M_PI / 11), 0,
    0, 0, 1, sin(9 * 2 * M_PI / 11), cos(9 * 2 * M_PI / 11), 0, sin(10 * 2 * M_PI / 11), cos(10 * 2 * M_PI / 11), 0,
    0, 0, 1, sin(10 * 2 * M_PI / 11), cos(10 * 2 * M_PI / 11), 0, sin(11 * 2 * M_PI / 11), cos(11 * 2 * M_PI / 11), 0,
    0, 0, 0, sin(0 * 2 * M_PI / 11), cos(0 * 2 * M_PI / 11), 0, sin(1 * 2 * M_PI / 11), cos(1 * 2 * M_PI / 11), 0,
    0, 0, 0, sin(1 * 2 * M_PI / 11), cos(1 * 2 * M_PI / 11), 0, sin(2 * 2 * M_PI / 11), cos(2 * 2 * M_PI / 11), 0,
    0, 0, 0, sin(2 * 2 * M_PI / 11), cos(2 * 2 * M_PI / 11), 0, sin(3 * 2 * M_PI / 11), cos(3 * 2 * M_PI / 11), 0,
    0, 0, 0, sin(3 * 2 * M_PI / 11), cos(3 * 2 * M_PI / 11), 0, sin(4 * 2 * M_PI / 11), cos(4 * 2 * M_PI / 11), 0,
    0, 0, 0, sin(4 * 2 * M_PI / 11), cos(4 * 2 * M_PI / 11), 0, sin(5 * 2 * M_PI / 11), cos(5 * 2 * M_PI / 11), 0,
    0, 0, 0, sin(5 * 2 * M_PI / 11), cos(5 * 2 * M_PI / 11), 0, sin(6 * 2 * M_PI / 11), cos(6 * 2 * M_PI / 11), 0,
    0, 0, 0, sin(6 * 2 * M_PI / 11), cos(6 * 2 * M_PI / 11), 0, sin(7 * 2 * M_PI / 11), cos(7 * 2 * M_PI / 11), 0,
    0, 0, 0, sin(7 * 2 * M_PI / 11), cos(7 * 2 * M_PI / 11), 0, sin(8 * 2 * M_PI / 11), cos(8 * 2 * M_PI / 11), 0,
    0, 0, 0, sin(8 * 2 * M_PI / 11), cos(8 * 2 * M_PI / 11), 0, sin(9 * 2 * M_PI / 11), cos(9 * 2 * M_PI / 11), 0,
    0, 0, 0, sin(9 * 2 * M_PI / 11), cos(9 * 2 * M_PI / 11), 0, sin(10 * 2 * M_PI / 11), cos(10 * 2 * M_PI / 11), 0,
    0, 0, 0, sin(10 * 2 * M_PI / 11), cos(10 * 2 * M_PI / 11), 0, sin(11 * 2 * M_PI / 11), cos(11 * 2 * M_PI / 11), 0,
  };


  static const GLfloat vertex_buffer_data1[] = {
    0, 0, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 1, 1, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 1, 0, 0, 0, 1,
    0, 1, 1, 0, 1, 0, 0, 0, 1,
    1, 1, 1, 0, 1, 1, 1, 1, 0,
    0, 1, 0, 0, 1, 1, 1, 1, 0,
    1, 1, 1, 1, 0, 1, 1, 1, 0,
    1, 0, 0, 1, 0, 1, 1, 1, 0,
    0.7, 0.7, 1 + 1, 0, 0, 1, 1, 0, 1,
    0.7, 0.7, 1 + 1, 1, 0, 1, 1, 1, 1,
    0.7, 0.7, 1 + 1, 1, 1, 1, 0, 1, 1,
    0.7, 0.7, 1 + 1, 0, 1, 1, 0, 0, 1,
    0.7, 0.7, -1, 0, 0, 0, 1, 0, 0,
    0.7, 0.7, -1, 1, 0, 0, 1, 1, 0,
    0.7, 0.7, -1, 1, 1, 0, 0, 1, 0,
    0.7, 0.7, -1, 0, 1, 0, 0, 0, 0,
  };

  static const GLfloat vertex_buffer_data0[] = {
      -1.0f, -1.0f, -1.0f,                       // triangle 1 : begin
      -1.0f, -1.0f, 1.0f,  -1.0f, 1.0f,  1.0f,   // triangle 1 : end
      1.0f,  1.0f,  -1.0f,                       // triangle 2 : begin
      -1.0f, -1.0f, -1.0f, -1.0f, 1.0f,  -1.0f,  // triangle 2 : end
      1.0f,  -1.0f, 1.0f,  -1.0f, -1.0f, -1.0f, 1.0f,  -1.0f, -1.0f, 1.0f,
      1.0f,  -1.0f, 1.0f,  -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
      -1.0f, -1.0f, 1.0f,  1.0f,  -1.0f, 1.0f,  -1.0f, 1.0f,  -1.0f, 1.0f,
      -1.0f, -1.0f, 1.0f,  -1.0f, -1.0f, -1.0f, -1.0f, 1.0f,  1.0f,  -1.0f,
      -1.0f, 1.0f,  1.0f,  -1.0f, 1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  -1.0f,
      -1.0f, 1.0f,  1.0f,  -1.0f, 1.0f,  -1.0f, -1.0f, 1.0f,  1.0f,  1.0f,
      1.0f,  -1.0f, 1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  -1.0f, -1.0f,
      1.0f,  -1.0f, 1.0f,  1.0f,  1.0f,  -1.0f, 1.0f,  -1.0f, -1.0f, 1.0f,
      1.0f,  1.0f,  1.0f,  1.0f,  -1.0f, 1.0f,  1.0f,  1.0f,  -1.0f, 1.0f};

  
  static const GLfloat color_buffer_data[] = {
    0 , 0 , 0 ,
    0 , 0 , 0.3 ,
    0 , 0 , 0.6 ,
    0 , 0 , 1 ,
    0 , 0.3 , 0 ,
    0 , 0.3 , 0.3 ,
    0 , 0.3 , 0.6 ,
    0 , 0.3 , 1 ,
    0 , 0.6 , 0 ,
    0 , 0.6 , 0.3 ,
    0 , 0.6 , 0.6 ,
    0 , 0.6 , 1 ,
    0 , 1 , 0 ,
    0 , 1 , 0.3 ,
    0 , 1 , 0.6 ,
    0 , 1 , 1 ,
    0.3 , 0 , 0 ,
    0.3 , 0 , 0.3 ,
    0.3 , 0 , 0.6 ,
    0.3 , 0 , 1 ,
    0.3 , 0.3 , 0 ,
    0.3 , 0.3 , 0.3 ,
    0.3 , 0.3 , 0.6 ,
    0.3 , 0.3 , 1 ,
    0.3 , 0.6 , 0 ,
    0.3 , 0.6 , 0.3 ,
    0.3 , 0.6 , 0.6 ,
    0.3 , 0.6 , 1 ,
    0.3 , 1 , 0 ,
    0.3 , 1 , 0.3 ,
    0.3 , 1 , 0.6 ,
    0.3 , 1 , 1 ,
    0.6 , 0 , 0 ,
    0.6 , 0 , 0.3 ,
    0.6 , 0 , 0.6 ,
    0.6 , 0 , 1 ,
    0.6 , 0.3 , 0 ,
    0.6 , 0.3 , 0.3 ,
    0.6 , 0.3 , 0.6 ,
    0.6 , 0.3 , 1 ,
    0.6 , 0.6 , 0 ,
    0.6 , 0.6 , 0.3 ,
    0.6 , 0.6 , 0.6 ,
    0.6 , 0.6 , 1 ,
    0.6 , 1 , 0 ,
    0.6 , 1 , 0.3 ,
    0.6 , 1 , 0.6 ,
    0.6 , 1 , 1 ,
    1 , 0 , 0 ,
    1 , 0 , 0.3 ,
    1 , 0 , 0.6 ,
    1 , 0 , 1 ,
    1 , 0.3 , 0 ,
    1 , 0.3 , 0.3 ,
    1 , 0.3 , 0.6 ,
    1 , 0.3 , 1 ,
    1 , 0.6 , 0 ,
    1 , 0.6 , 0.3 ,
    1 , 0.6 , 0.6 ,
    1 , 0.6 , 1 ,
    1 , 1 , 0 ,
    1 , 1 , 0.3 ,
    1 , 1 , 0.6 ,
    1 , 1 , 1 ,

    0 , 0 , 0 ,
    0 , 0 , 0.3 ,
    0 , 0 , 0.6 ,
    0 , 0 , 1 ,
    0 , 0.3 , 0 ,
    0 , 0.3 , 0.3 ,
    0 , 0.3 , 0.6 ,
    0 , 0.3 , 1 ,
    0 , 0.6 , 0 ,
    0 , 0.6 , 0.3 ,
    0 , 0.6 , 0.6 ,
    0 , 0.6 , 1 ,
    0 , 1 , 0 ,
    0 , 1 , 0.3 ,
    0 , 1 , 0.6 ,
    0 , 1 , 1 ,
    0.3 , 0 , 0 ,
    0.3 , 0 , 0.3 ,
    0.3 , 0 , 0.6 ,
    0.3 , 0 , 1 ,
    0.3 , 0.3 , 0 ,
    0.3 , 0.3 , 0.3 ,
    0.3 , 0.3 , 0.6 ,
    0.3 , 0.3 , 1 ,
    0.3 , 0.6 , 0 ,
    0.3 , 0.6 , 0.3 ,
    0.3 , 0.6 , 0.6 ,
    0.3 , 0.6 , 1 ,
    0.3 , 1 , 0 ,
    0.3 , 1 , 0.3 ,
    0.3 , 1 , 0.6 ,
    0.3 , 1 , 1 ,
    0.6 , 0 , 0 ,
    0.6 , 0 , 0.3 ,
    0.6 , 0 , 0.6 ,
    0.6 , 0 , 1 ,
    0.6 , 0.3 , 0 ,
    0.6 , 0.3 , 0.3 ,
    0.6 , 0.3 , 0.6 ,
    0.6 , 0.3 , 1 ,
    0.6 , 0.6 , 0 ,
    0.6 , 0.6 , 0.3 ,
    0.6 , 0.6 , 0.6 ,
    0.6 , 0.6 , 1 ,
    0.6 , 1 , 0 ,
    0.6 , 1 , 0.3 ,
    0.6 , 1 , 0.6 ,
    0.6 , 1 , 1 ,
    1 , 0 , 0 ,
    1 , 0 , 0.3 ,
    1 , 0 , 0.6 ,
    1 , 0 , 1 ,
    1 , 0.3 , 0 ,
    1 , 0.3 , 0.3 ,
    1 , 0.3 , 0.6 ,
    1 , 0.3 , 1 ,
    1 , 0.6 , 0 ,
    1 , 0.6 , 0.3 ,
    1 , 0.6 , 0.6 ,
    1 , 0.6 , 1 ,
    1 , 1 , 0 ,
    1 , 1 , 0.3 ,
    1 , 1 , 0.6 ,
    1 , 1 , 1 ,
  };


  this->object0 = create3DObject(GL_TRIANGLES, sizeof(vertex_buffer_data0) / sizeof(vertex_buffer_data0[0]) / 3, vertex_buffer_data0, color_buffer_data, GL_FILL);
  this->object1 = create3DObject(GL_TRIANGLES, sizeof(vertex_buffer_data1) / sizeof(vertex_buffer_data1[0]) / 3, vertex_buffer_data1, color_buffer_data, GL_FILL);
  this->object2 = create3DObject(GL_TRIANGLES, sizeof(vertex_buffer_data2) / sizeof(vertex_buffer_data2[0]) / 3, vertex_buffer_data2, color_buffer_data, GL_FILL);
  this->object3 = create3DObject(GL_TRIANGLES, sizeof(vertex_buffer_data3) / sizeof(vertex_buffer_data3[0]) / 3, vertex_buffer_data3, color_buffer_data, GL_FILL);
}

void Ball::draw(glm::mat4 VP, int index) {
  Matrices.model = glm::mat4(1.0f);
  glm::mat4 translate = glm::translate(this->position);  // glTranslatef
  glm::mat4 rotate =
      glm::rotate((float)(this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
  // No need as coords centered at 0, 0, 0 of cube arouund which we waant to
  // rotate rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
  Matrices.model *= (translate * rotate);
  glm::mat4 MVP = VP * Matrices.model;
  glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);

  if (index == 0)
    draw3DObject(this->object0);
  if (index == 1)
    draw3DObject(this->object1);
  if (index == 2)
    draw3DObject(this->object2);
  if (index == 3)
    draw3DObject(this->object3);
}

void Ball::set_position(float x, float y) {
  this->position = glm::vec3(x, y, 0);
}

void Ball::translate(float x, float y, float z) {
  position = glm::vec3(position.x + x, position.y + y, position.z + z);
}

void Ball::tick() {
  // this->rotation += speed;
  // this->position.x -= speed;
  // this->position.y -= speed;
}
