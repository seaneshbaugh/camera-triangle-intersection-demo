#ifndef SRC_TRIANGLE_HPP
#define SRC_TRIANGLE_HPP

#include <iomanip>
#include <sstream>
#include <string>

#include <glm/glm.hpp>

#include "util.hpp"

class Triangle {
public:
  glm::vec3 v0;
  glm::vec3 v1;
  glm::vec3 v2;

  Triangle();
  Triangle(glm::vec3 v0_initial, glm::vec3 v1_initial, glm::vec3 v2_initial);
  std::string ToString(const int precision = 2);
};

#endif
