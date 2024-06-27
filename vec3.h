
#pragma once

//------------------------------------------------------------------------------
// This file is part of the PTrace Engine.
// File: vec3.h
// 
// Created by pyoneerC on 6/27/2024
// Copyright (c) 2024 pyoneerC. All rights reserved.
//
// Description:
// [Brief description of the file's contents and purpose]
//------------------------------------------------------------------------------

class vec3 {

  vec3() = default;
  vec3(const float e0, const float e1, const float e2) : e{e0, e1, e2} {}

  [[nodiscard]] float x() const { return e[0]; }
  [[nodiscard]] float y() const { return e[1]; }
  [[nodiscard]] float z() const { return e[2]; }
  [[nodiscard]] float r() const { return e[0]; }
  [[nodiscard]] float g() const { return e[1]; }
  [[nodiscard]] float b() const { return e[2]; }

  const vec3& operator+() const;
  vec3 operator-() const;
  float operator[](const int i) const;

  vec3& operator+=(const vec3& v);
  vec3& operator-=(const vec3& v);
  vec3& operator*=(const vec3& v);
  vec3& operator/=(const vec3& v);

  vec3& operator*=(float t);
  vec3& operator/=(float t);

  float lenght() const;

  float squared_length() const;

  void make_unit_vector();

  float e[3];
};
