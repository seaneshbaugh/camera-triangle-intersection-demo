#ifndef SRC_CAMERA_HPP
#define SRC_CAMERA_HPP

#include <cmath>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "util.hpp"

enum CameraMovement {
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
};

class Camera
{
public:
  glm::vec3 position;
  glm::vec3 front;
  glm::vec3 up;
  glm::vec3 right;
  glm::vec3 world_up;
  float yaw;
  float pitch;
  float movement_speed;
  float mouse_sensitivity;
  float zoom;

  Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 world_up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = -90.0f, float pitch = 0.0f);
  Camera(float position_x, float position_y, float position_z, float world_up_x, float world_up_y, float world_up_z, float pitch, float yaw);
  void ProcessKeyboardInput(const CameraMovement direction, const float delta_time);
  void ProcessMouseMovement(const float x_offset, const float y_offset, const bool constrain_pitch = true);
  void ProcessMouseScroll(const float y_offset);
  std::string ToString(const int precision = 2);
  glm::mat4 ViewMatrix();

private:
  void UpdateCameraVectors();
};

#endif
