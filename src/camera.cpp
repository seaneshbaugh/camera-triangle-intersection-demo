#include "camera.hpp"

Camera::Camera(glm::vec3 position_initial, glm::vec3 world_up_initial, float yaw_initial, float pitch_initial) : front(glm::vec3(0.0f, 0.0f, -1.0f)), movement_speed(8.0f), mouse_sensitivity(0.05f), zoom(45.0f) {
  this->position = position_initial;

  this->world_up = world_up_initial;

  this->yaw = yaw_initial;

  this->pitch = pitch_initial;

  this->UpdateCameraVectors();
}

Camera::Camera(float position_x, float position_y, float position_z, float world_up_x, float world_up_y, float world_up_z, float yaw_initial, float pitch_initial) : front(glm::vec3(0.0f, 0.0f, -1.0f)), movement_speed(8.0f), mouse_sensitivity(0.05f), zoom(45.0f) {
  this->position = glm::vec3(position_x, position_y, position_z);

  this->world_up = glm::vec3(world_up_x, world_up_y, world_up_z);

  this->yaw = yaw_initial;

  this->pitch = pitch_initial;

  this->UpdateCameraVectors();
}

void Camera::ProcessKeyboardInput(const CameraMovement direction, const float delta_time) {
  const float velocity = this->movement_speed * delta_time;

  if (direction == FORWARD) {
    this->position += this->front * velocity;
  }

  if (direction == BACKWARD) {
    this->position -= this->front * velocity;
  }

  if (direction == LEFT) {
    this->position -= this->right * velocity;
  }

  if (direction == RIGHT) {
    this->position += this->right * velocity;
  }

  this->position.y = 0.0f;
}

void Camera::ProcessMouseMovement(const float x_offset, const float y_offset, const bool constrain_pitch) {
  this->yaw += x_offset * this->mouse_sensitivity;

  this->pitch += y_offset * this->mouse_sensitivity;

  if (constrain_pitch) {
    if (this->pitch > 89.0f) {
      this->pitch = 89.0f;
    } else {
      if (this->pitch < -89.0f) {
        this->pitch = -89.0f;
      }
    }
  }

  this->UpdateCameraVectors();
}

void Camera::ProcessMouseScroll(const float y_offset) {
  this->zoom -= y_offset;

  if (this->zoom <= 1.0f) {
    this->zoom = 1.0f;
  } else {
    if (this->zoom >= 45.0f) {
      this->zoom = 45.0f;
    }
  }
}

std::string Camera::ToString(const int precision) {
  std::ostringstream result;

  result << "#<Camera:";

  result << "0x" << std::hex << std::noshowbase << std::setw(16) << std::setfill('0');

  result << reinterpret_cast<unsigned long>(this);

  result << " position=" << util::Vec3ToString(this->position, precision);

  result << ", front=" << util::Vec3ToString(this->front, precision);

  result << ", up=" << util::Vec3ToString(this->up, precision);

  result << ", right=" << util::Vec3ToString(this->right, precision);

  result << ", world_up=" << util::Vec3ToString(this->world_up);

  result << std::setprecision(precision) << std::fixed;

  result << ", yaw=" << this->yaw;

  result << ", pitch=" << this->pitch;

  result << ", zoom=" << this->zoom;

  result << ">";

  return result.str();
}

glm::mat4 Camera::ViewMatrix() {
  return glm::lookAt(this->position, this->position + this->front, this->up);
}

void Camera::UpdateCameraVectors() {
  glm::vec3 updated_front;

  updated_front.x = std::cos(glm::radians(this->yaw)) * std::cos(glm::radians(this->pitch));

  updated_front.y = std::sin(glm::radians(this->pitch));

  updated_front.z = std::sin(glm::radians(this->yaw)) * std::cos(glm::radians(this->pitch));

  this->front = glm::normalize(updated_front);

  this->right = glm::normalize(glm::cross(this->front, this->world_up));

  this->up = glm::normalize(glm::cross(this->right, this->front));
}
