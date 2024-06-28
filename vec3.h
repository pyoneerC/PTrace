
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
public:
  vec3() : e{0.0f, 0.0f, 0.0f} {}
  vec3(const float e0, const float e1, const float e2) : e{e0, e1, e2} {}

  [[nodiscard]] float x() const { return e[0]; }
  [[nodiscard]] float y() const { return e[1]; }
  [[nodiscard]] float z() const { return e[2]; }
  [[nodiscard]] float r() const { return e[0]; }
  [[nodiscard]] float g() const { return e[1]; }
  [[nodiscard]] float b() const { return e[2]; }

  vec3 operator-() const;

  vec3 operator+(const vec3& v) const;
  vec3& operator-(const vec3& v);
  vec3& operator*(const vec3& v);
  vec3& operator/(const vec3& v);

  float operator[](int i) const;

  vec3& operator+=(const vec3& v);
  vec3& operator-=(const vec3& v);
  vec3& operator*=(const vec3& v);
  vec3& operator/=(const vec3& v);

  bool operator==(const vec3& v) const;
  bool operator!=(const vec3& v) const;
  bool operator<(const vec3& v) const;
  bool operator>(const vec3& v) const;
  bool operator<=(const vec3& v) const;
  bool operator>=(const vec3& v) const;

  vec3 operator!() const;

  vec3 operator*(float t) const;
  vec3 operator/(float t) const;

  [[nodiscard]] float length() const;

  [[nodiscard]] float squared_length() const;

  void make_unit_vector();

  float e[3];
};

float dot(const vec3& v1, const vec3& v2);
vec3 cross(const vec3& v1, const vec3& v2);