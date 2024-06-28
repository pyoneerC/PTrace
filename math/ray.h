
#pragma once

//------------------------------------------------------------------------------
// This file is part of the PTrace Engine.
// File: ray.h
// 
// Created by pyoneerC on 6/27/2024
// Copyright (c) 2024 pyoneerC. All rights reserved.
//
// Description:
// [Brief description of the file's contents and purpose]
//------------------------------------------------------------------------------

#include "vec3.h"

class ray {
public:
  ray() = default;
  ray(const vec3& a, const vec3& b) : A(a), B(b) {}
  [[nodiscard]] vec3 origin() const { return A; }
  [[nodiscard]] vec3 direction() const { return B; }
  [[nodiscard]] vec3 point_at_parameter(const float t) const { return A + (B * t); }

  vec3 A;
  vec3 B;
};

bool inline doesRayHitSphere(const vec3& sphereCenter, float sphereRadius, const ray& ray) {
  vec3 vectorFromSphereCenterToRayOrigin = ray.origin() - sphereCenter;
  float rayDirectionDotProduct = dot(ray.direction(), ray.direction());
  float ocDotRayDirectionTimesTwo = 2.0f * dot(vectorFromSphereCenterToRayOrigin, ray.direction());
  float ocDotProductMinusRadiusSquared = dot(vectorFromSphereCenterToRayOrigin, vectorFromSphereCenterToRayOrigin) - sphereRadius * sphereRadius;
  float discriminant = ocDotRayDirectionTimesTwo * ocDotRayDirectionTimesTwo - 4 * rayDirectionDotProduct * ocDotProductMinusRadiusSquared;
  return discriminant > 0;
}

vec3 inline color(const ray& r) {
  if (doesRayHitSphere(vec3(0, 0, -1), 0.5f, r)) {
    return {1, 0, 0};
  }
  vec3 unit_direction = !r.direction();
  float t = 0.5f * (unit_direction.y() + 1.0f);
  return vec3(1.0f, 1.0f, 1.0f) * (1.0f - t) + vec3(0.5f, 0.7f, 1.0f) * t;
}

