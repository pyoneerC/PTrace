
#pragma once

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
#include <iostream>



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
  return vec3(-e[0], -e[1], -e[2]);
}

vec3& vec3::operator+(const vec3& v) {
  e[0] += v.e[0];
  e[1] += v.e[1];
  e[2] += v.e[2];
  return *this;
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

vec3& vec3::operator*=(float t) {
  e[0] *= t;
  e[1] *= t;
  e[2] *= t;
  return *this;
}

vec3& vec3::operator/=(float t) {
  float k = 1.0/t;
  e[0] *= k;
  e[1] *= k;
  e[2] *= k;
  return *this;
}

vec3 vec3::operator*(float t) const {
  return vec3(e[0]*t, e[1]*t, e[2]*t);
}

float vec3::lenght() const {
  return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
}

float vec3::squared_length() const {
  return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}

void vec3::make_unit_vector() {
  float k = 1.0 / lenght();
  e[0] *= k;
  e[1] *= k;
  e[2] *= k;
}

std::istream& operator>>(std::istream& is, vec3& t) {
  is >> t.e[0] >> t.e[1] >> t.e[2];
  return is;
}

std::ostream& operator<<(std::ostream& os, const vec3& t) {
  os << t.e[0] << " " << t.e[1] << " " << t.e[2];
  return os;
}
