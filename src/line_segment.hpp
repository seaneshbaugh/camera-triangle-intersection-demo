#ifndef SRC_LINE_SEGMENT_HPP
#define SRC_LINE_SEGMENT_HPP

#include <iomanip>
#include <sstream>
#include <string>
#include <glm/glm.hpp>
#include "util.hpp"

struct LineSegment {
public:
  glm::vec3 p0;
  glm::vec3 p1;

  LineSegment();
  LineSegment(glm::vec3 p0_initial, glm::vec3 p1_initial);
  std::string ToString(const int precision = 2);
};

#endif
