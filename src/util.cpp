#include "util.hpp"

std::string util::Vec3ToString(const glm::vec3 vector, const int precision) {
  std::ostringstream result;

  result << std::setprecision(precision) << std::fixed;

  result << "[" << vector.x << ", " << vector.y << ", " << vector.z << "]";

  return result.str();
}

std::string util::Vec4ToString(const glm::vec4 vector, const int precision) {
  std::ostringstream result;

  result << std::setprecision(precision) << std::fixed;

  result << "[" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << "]";

  return result.str();
}

std::string util::Mat4ToString(const glm::mat4 matrix, const int precision) {
  std::ostringstream result;

  result << std::setprecision(precision) << std::fixed;

  result << "[";

  for (int x = 0; x < 4; x += 1) {
    for (int y = 0; y < 4; y += 1) {
      result << matrix[y][x];

      if (y < 3) {
        result << ", ";
      }
    }

    if (x < 3) {
      result << "," << std::endl;
    } else {
      result << "]";
    }
  }

  return result.str();
}
