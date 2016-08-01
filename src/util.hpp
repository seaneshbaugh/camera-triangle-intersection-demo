#ifndef SRC_UTIL_HPP
#define SRC_UTIL_HPP

#include <iomanip>
#include <sstream>
#include <string>

#include <glm/glm.hpp>

namespace util {
std::string Vec3ToString(const glm::vec3 vector, const int precision = 2);

std::string Vec4ToString(const glm::vec4 vector, const int precision = 2);

std::string Mat4ToString(const glm::mat4 matrix, const int precision = 2);
}

#endif
