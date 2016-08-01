#include "intersection.hpp"

// Copyright 2001 softSurfer, 2012 Dan Sunday
// This code may be freely used and modified for any purpose
// providing that this copyright notice is included with it.
// SoftSurfer makes no warranty for this code, and cannot be held
// liable for any real or imagined damage resulting from its use.
// Users of this code must verify correctness for their application.
intersection::IntersectionResult intersection::FindIntersection(const LineSegment ray, const Triangle triangle, glm::vec3* result) {
  const glm::vec3 u = triangle.v1 - triangle.v0;

  const glm::vec3 v = triangle.v2 - triangle.v0;

  const glm::vec3 n = glm::cross(u, v);

  if (n == glm::vec3(0.0f, 0.0f, 0.0f)) {
    return intersection::DEGENERATE;
  }

  const glm::vec3 dir = ray.p1 - ray.p0;

  const glm::vec3 w0 = ray.p0 - triangle.v0;

  const float a = glm::dot(n, w0) * -1.0f;

  const float b = glm::dot(n, dir);

  if (fabs(static_cast<double>(b)) < static_cast<double>(intersection::EPSILON)) {
    if (a == 0.0f) {
      return intersection::SAME_PLANE;
    } else {
      return intersection::DISJOINT;
    }
  }

  const float r = a / b;

  if (r < 0.0f) {
    return intersection::DISJOINT;
  }

  *result = ray.p0 + r * dir;

  const float uu = glm::dot(u, u);

  const float uv = glm::dot(u, v);

  const float vv = glm::dot(v, v);

  const glm::vec3 w = *result - triangle.v0;

  const float wu = glm::dot(w, u);

  const float wv = glm::dot(w, v);

  const float d = uv * uv - uu * vv;

  const float s = (uv * wv - vv * wu) / d;

  if (s < 0.0f || s > 1.0f) {
    return intersection::DISJOINT;
  }

  const float t = (uv * wu - uu * wv) / d;

  if (t < 0.0f || (s + t) > 1.0f) {
    return intersection::DISJOINT;
  }

  return intersection::INTERSECTS;
}
