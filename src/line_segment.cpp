#include "line_segment.hpp"

LineSegment::LineSegment() : p0(glm::vec3(0.0f, 0.0f, 0.0f)), p1(glm::vec3(1.0f, 1.0f, 1.0f)) {}

LineSegment::LineSegment(glm::vec3 p0_initial, glm::vec3 p1_initial) : p0(p0_initial), p1(p1_initial) {}

std::string LineSegment::ToString(const int precision) {
  std::ostringstream result;

  result << "#<LineSegment:";

  result << "0x" << std::hex << std::noshowbase << std::setw(16) << std::setfill('0');

  result << reinterpret_cast<unsigned long>(this);

  result << " p0=" << util::Vec3ToString(this->p0, precision);

  result << ", p1=" << util::Vec3ToString(this->p1, precision);

  result << ">";

  return result.str();
}
