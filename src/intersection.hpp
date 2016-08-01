#ifndef SRC_INTERSECTION_HPP
#define SRC_INTERSECTION_HPP

#include <cmath>

#include <glm/glm.hpp>

#include "line_segment.hpp"
#include "triangle.hpp"

namespace intersection {
  const float EPSILON = 0.00000001f;

  enum IntersectionResult {
    DEGENERATE = -1,
    DISJOINT,
    INTERSECTS,
    SAME_PLANE
  };

  IntersectionResult FindIntersection(LineSegment r, Triangle t, glm::vec3* result);
}

#endif
