#include "triangle.hpp"

Triangle::Triangle() : v0(glm::vec3(0.0f, 1.0f, 0.0f)), v1(glm::vec3(1.0f, 0.0f, 0.0f)), v2(glm::vec3(-1.0f, 0.0f, 0.0f)) {}

Triangle::Triangle(glm::vec3 v0_initial, glm::vec3 v1_initial, glm::vec3 v2_initial) : v0(v0_initial), v1(v1_initial), v2(v2_initial) {}

std::string Triangle::ToString(const int precision) {
  std::ostringstream result;

  result << "#<Triangle:";

  result << "0x" << std::hex << std::noshowbase << std::setw(16) << std::setfill('0');

  result << reinterpret_cast<unsigned long>(this);

  result << " v0=" << util::Vec3ToString(this->v0, precision);

  result << ", v1=" << util::Vec3ToString(this->v1, precision);

  result << ", v2=" << util::Vec3ToString(this->v2, precision);

  result << ">";

  return result.str();
}
