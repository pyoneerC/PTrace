#include <iostream>

//first raytracer. 27.06.2024. 19 yo. 4:00 pm

//remember testing with catch2

#include "vec3.h"

int main() {
  vec3 v1(1.0, 2.0, 3.0);
  vec3 v2(4.0, 5.0, 6.0);
  vec3 v3 = v1 + v2;
  std::cout << v3.x() << " " << v3.y() << " " << v3.z() << std::endl;
  return 0;
}
