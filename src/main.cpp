#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "line_segment.hpp"
#include "triangle.hpp"
#include "util.hpp"

int main(int argc, char** argv) {
  Triangle t;

  std::cout << t.ToString() << std::endl;

  LineSegment l;

  std::cout << l.ToString() << std::endl;

  return 0;
}
