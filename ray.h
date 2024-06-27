
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
  vec3 origin() const { return A; }
  vec3 direction() const { return B; }
  vec3 point_at_parameter(float t) const { return A + t * B; }

  vec3 A;
  vec3 B;
};
