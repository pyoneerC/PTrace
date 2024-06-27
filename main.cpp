#include <iostream>

//first raytracer. 27.06.2024. 19 yo. 4:00 pm

//remember testing with catch2

#include "vec3.h"
#include "ray.h"
#include "fmt/core.h"

int main() {
  vec3 a(1, 2, 3);
  vec3 b(4, 5, 6);
  vec3 c = a + b;
  c *= 2;
  ray r(a, b);

  fmt::print("c: {} {} {}\n", c.x(), c.y(), c.z());
  fmt::print("ray origin: {} {} {}\n", r.origin().x(), r.origin().y(), r.origin().z());
  return 0;

}
