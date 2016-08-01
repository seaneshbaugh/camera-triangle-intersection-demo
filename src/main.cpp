#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "util.hpp"

int main(int argc, char** argv) {
  glm::vec3 v = glm::vec3(1.0f, 2.0f, 3.0f);

  std::cout << util::Vec3ToString(v) << std::endl;

  return 0;
}
