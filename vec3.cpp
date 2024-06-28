//------------------------------------------------------------------------------
// This file is part of the PTrace Engine.
// File: vec3.cpp
// 
// Created by pyoneerC on 6/27/2024
// Copyright (c) 2024 pyoneerC. All rights reserved.
//
// Description:
// [Brief description of the file's contents and purpose]
//------------------------------------------------------------------------------

#include "vec3.h"
#include <cmath>

vec3& vec3::operator-(const vec3& v) {
  e[0] -= v.e[0];
  e[1] -= v.e[1];
  e[2] -= v.e[2];
  return *this;
}

vec3& vec3::operator*(const vec3& v) {
  e[0] *= v.e[0];
  e[1] *= v.e[1];
  e[2] *= v.e[2];
  return *this;
}

vec3& vec3::operator/(const vec3& v) {
  e[0] /= v.e[0];
  e[1] /= v.e[1];
  e[2] /= v.e[2];
  return *this;
}

vec3 vec3::operator-() const {
  return {-e[0], -e[1], -e[2]};
}

vec3 vec3::operator+(const vec3& v) const {
  return {e[0] + v.e[0], e[1] + v.e[1], e[2] + v.e[2]};
}

float vec3::operator[](const int i) const {
  return e[i];
}

vec3& vec3::operator+=(const vec3& v) {
  e[0] += v.e[0];
  e[1] += v.e[1];
  e[2] += v.e[2];
  return *this;
}

vec3& vec3::operator-=(const vec3& v) {
  e[0] -= v.e[0];
  e[1] -= v.e[1];
  e[2] -= v.e[2];
  return *this;
}

vec3& vec3::operator*=(const vec3& v) {
  e[0] *= v.e[0];
  e[1] *= v.e[1];
  e[2] *= v.e[2];
  return *this;
}

vec3& vec3::operator/=(const vec3& v) {
  e[0] /= v.e[0];
  e[1] /= v.e[1];
  e[2] /= v.e[2];
  return *this;
}

bool vec3::operator==(const vec3& v) const {
  return e[0] == v.e[0] && e[1] == v.e[1] && e[2] == v.e[2];
}

bool vec3::operator!=(const vec3& v) const {
  return !(e[0] == v.e[0] && e[1] == v.e[1] && e[2] == v.e[2]);
}

bool vec3::operator<(const vec3& v) const {
  return e[0] < v.e[0] && e[1] < v.e[1] && e[2] < v.e[2];
}

bool vec3::operator>(const vec3& v) const {
  return e[0] > v.e[0] && e[1] > v.e[1] && e[2] > v.e[2];
}

bool vec3::operator<=(const vec3& v) const {
  return e[0] <= v.e[0] && e[1] <= v.e[1] && e[2] <= v.e[2];
}

bool vec3::operator>=(const vec3& v) const {
  return e[0] >= v.e[0] && e[1] >= v.e[1] && e[2] >= v.e[2];
}

vec3 vec3::operator!() const {
  return {-e[0], -e[1], -e[2]};
}

vec3 vec3::operator*(float t) const {
  return {e[0]*t, e[1]*t, e[2]*t};
}

vec3 vec3::operator/(float t) const {
  return {e[0] / t, e[1] / t, e[2] / t};
}

float vec3::length() const {
  return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
}

float vec3::squared_length() const {
  return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}


void vec3::make_unit_vector() {
  double k = 1.0 / length();
  e[0] *= k;
  e[1] *= k;
  e[2] *= k;
}

float dot(const vec3& v1, const vec3& v2) {
  return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

vec3 cross(const vec3& v1, const vec3& v2) {
  return vec3(
    v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
    v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2],
    v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]
  );
}
