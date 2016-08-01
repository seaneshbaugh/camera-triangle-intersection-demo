#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "camera.hpp"
#include "intersection.hpp"
#include "line_segment.hpp"
#include "triangle.hpp"
#include "util.hpp"

int main(int argc, char** argv) {
  Triangle t = Triangle(glm::vec3(0.0f, 2.0f, 0.0f), glm::vec3(2.0f, -2.0f, 0.0f), glm::vec3(-2.0f, -2.0f, 0.0f));

  std::cout << "t = " << t.ToString() << std::endl;

  Camera c = Camera(glm::vec3(0.0f, 0.0f, 2.0f));

  std::cout << "c = " << c.ToString() << std::endl << std::endl;

  for (int i = 0; i < 5; i += 1) {
    std::cout << std::setprecision(2) << std::fixed;

    const float x_offset = static_cast<float>(i) * 50.0f;

    const float y_offset = static_cast<float>(i) * 50.0f;

    std::cout << "Moving c " << x_offset << " x " << y_offset << std::endl;

    c.ProcessMouseMovement(x_offset, y_offset, true);

    std::cout << "c = " << c.ToString() << std::endl;

    LineSegment r = LineSegment(c.position, c.position + (c.front * 10.0f));

    std::cout << "r = " << r.ToString() << std::endl;

    glm::vec3 result;

    switch(intersection::FindIntersection(r, t, &result)) {
    case intersection::DEGENERATE:
      std::cout << "t is degenerate" << std::endl;

      break;
    case intersection::DISJOINT:
      std::cout << "t and r are disjoint" << std::endl;

      break;
    case 1:
      std::cout << "t and r intersect in unique point " << util::Vec3ToString(result) << std::endl;

      break;
    case 2:
      std::cout << "t and r are in the same plane" << std::endl;

      break;
    }

    if (i < 4) {
      std::cout << std::endl;
    }
  }

  return 0;
}
