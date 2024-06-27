//------------------------------------------------------------------------------
// This file is part of the PTrace Engine.
// File: test_ray.cpp
// 
// Created by pyoneerC on 6/27/2024
// Copyright (c) 2024 pyoneerC. All rights reserved.
//
// Description:
// [Brief description of the file's contents and purpose]
//------------------------------------------------------------------------------

#include "../ray.h"
#include "gtest/gtest.h"

TEST(RayTest, TestRayOrigin) {
  vec3 origin(1.0f, 2.0f, 3.0f);
  vec3 direction(4.0f, 5.0f, 6.0f);
  ray r(origin, direction);

  EXPECT_FLOAT_EQ(r.origin().x(), 1.0f);
  EXPECT_FLOAT_EQ(r.origin().y(), 2.0f);
  EXPECT_FLOAT_EQ(r.origin().z(), 3.0f);
}

TEST(RayTest, TestRayDirection) {
  vec3 origin(1.0f, 2.0f, 3.0f);
  vec3 direction(4.0f, 5.0f, 6.0f);
  ray r(origin, direction);

  EXPECT_FLOAT_EQ(r.direction().x(), 4.0f);
  EXPECT_FLOAT_EQ(r.direction().y(), 5.0f);
  EXPECT_FLOAT_EQ(r.direction().z(), 6.0f);
}

TEST(RayTest, TestRayPointAtParameter) {
  vec3 origin(1.0f, 2.0f, 3.0f);
  vec3 direction(4.0f, 5.0f, 6.0f);
  ray r(origin, direction);

  vec3 point = r.point_at_parameter(2.0f);

  EXPECT_FLOAT_EQ(point.x(), 9.0f);
  EXPECT_FLOAT_EQ(point.y(), 12.0f);
  EXPECT_FLOAT_EQ(point.z(), 15.0f);
}

TEST(RayTest, TestRayParametrizedConstructor) {
  ray r;

  EXPECT_FLOAT_EQ(r.origin().x(), 0.0f);
  EXPECT_FLOAT_EQ(r.origin().y(), 0.0f);
  EXPECT_FLOAT_EQ(r.origin().z(), 0.0f);

  EXPECT_FLOAT_EQ(r.direction().x(), 0.0f);
  EXPECT_FLOAT_EQ(r.direction().y(), 0.0f);
  EXPECT_FLOAT_EQ(r.direction().z(), 0.0f);

  ray r2(vec3(1.0f, 2.0f, 3.0f), vec3(4.0f, 5.0f, 6.0f));

  EXPECT_FLOAT_EQ(r2.origin().x(), 1.0f);
  EXPECT_FLOAT_EQ(r2.origin().y(), 2.0f);
  EXPECT_FLOAT_EQ(r2.origin().z(), 3.0f);

  EXPECT_FLOAT_EQ(r2.direction().x(), 4.0f);
  EXPECT_FLOAT_EQ(r2.direction().y(), 5.0f);
  EXPECT_FLOAT_EQ(r2.direction().z(), 6.0f);
}

TEST(RayTest, TestRayPointAtParameterWithNegativeT) {
  vec3 origin(1.0f, 2.0f, 3.0f);
  vec3 direction(4.0f, 5.0f, 6.0f);
  ray r(origin, direction);

  vec3 point = r.point_at_parameter(-2.0f);

  EXPECT_FLOAT_EQ(point.x(), -7.0f);
  EXPECT_FLOAT_EQ(point.y(), -8.0f);
  EXPECT_FLOAT_EQ(point.z(), -9.0f);
}

TEST(RayTest, TestRayPointAtParameterWithZeroT) {
  vec3 origin(1.0f, 2.0f, 3.0f);
  vec3 direction(4.0f, 5.0f, 6.0f);
  ray r(origin, direction);

  vec3 point = r.point_at_parameter(0.0f);

  EXPECT_FLOAT_EQ(point.x(), 1.0f);
  EXPECT_FLOAT_EQ(point.y(), 2.0f);
  EXPECT_FLOAT_EQ(point.z(), 3.0f);
}

TEST(RayTest, TestRayPointAtParameterWithFractionalT) {
  vec3 origin(1.0f, 2.0f, 3.0f);
  vec3 direction(4.0f, 5.0f, 6.0f);
  ray r(origin, direction);

  vec3 point = r.point_at_parameter(0.5f);

  EXPECT_FLOAT_EQ(point.x(), 3.0f);
  EXPECT_FLOAT_EQ(point.y(), 4.5f);
  EXPECT_FLOAT_EQ(point.z(), 6.0f);
}

TEST(RayTest, TestRayPointAtParameterWithNegativeFractionalT) {
  vec3 origin(1.0f, 2.0f, 3.0f);
  vec3 direction(4.0f, 5.0f, 6.0f);
  ray r(origin, direction);

  vec3 point = r.point_at_parameter(-0.5f);

  EXPECT_FLOAT_EQ(point.x(), -1.0f);
  EXPECT_FLOAT_EQ(point.y(), -0.5f);
  EXPECT_FLOAT_EQ(point.z(), 0.0f);
}

TEST(RayTest, TestRayDefaultConstructor) {
  ray r;

  EXPECT_FLOAT_EQ(r.origin().x(), 0.0f);
  EXPECT_FLOAT_EQ(r.origin().y(), 0.0f);
  EXPECT_FLOAT_EQ(r.origin().z(), 0.0f);

  EXPECT_FLOAT_EQ(r.direction().x(), 0.0f);
  EXPECT_FLOAT_EQ(r.direction().y(), 0.0f);
  EXPECT_FLOAT_EQ(r.direction().z(), 0.0f);
}

TEST(RayTest, TestRayCopyConstructor) {
  ray r(vec3(1.0f, 2.0f, 3.0f), vec3(4.0f, 5.0f, 6.0f));
  ray r2 = r;

  EXPECT_FLOAT_EQ(r2.origin().x(), 1.0f);
  EXPECT_FLOAT_EQ(r2.origin().y(), 2.0f);
  EXPECT_FLOAT_EQ(r2.origin().z(), 3.0f);

  EXPECT_FLOAT_EQ(r2.direction().x(), 4.0f);
  EXPECT_FLOAT_EQ(r2.direction().y(), 5.0f);
  EXPECT_FLOAT_EQ(r2.direction().z(), 6.0f);
}

TEST(RayTest, TestRayAssignmentOperator) {
  ray r(vec3(1.0f, 2.0f, 3.0f), vec3(4.0f, 5.0f, 6.0f));
  ray r2;
  r2 = r;

  EXPECT_FLOAT_EQ(r2.origin().x(), 1.0f);
  EXPECT_FLOAT_EQ(r2.origin().y(), 2.0f);
  EXPECT_FLOAT_EQ(r2.origin().z(), 3.0f);

  EXPECT_FLOAT_EQ(r2.direction().x(), 4.0f);
  EXPECT_FLOAT_EQ(r2.direction().y(), 5.0f);
  EXPECT_FLOAT_EQ(r2.direction().z(), 6.0f);
}

TEST(RayTest, TestRayWithLargeNumbers) {
  vec3 origin(1e9f, 1e9f, 1e9f);
  vec3 direction(1e9f, 1e9f, 1e9f);
  ray r(origin, direction);

  vec3 point = r.point_at_parameter(2.0f);

  EXPECT_FLOAT_EQ(point.x(), 3e9f);
  EXPECT_FLOAT_EQ(point.y(), 3e9f);
  EXPECT_FLOAT_EQ(point.z(), 3e9f);
}

TEST(RayTest, TestRayWithSmallNumbers) {
  vec3 origin(1e-9f, 1e-9f, 1e-9f);
  vec3 direction(1e-9f, 1e-9f, 1e-9f);
  ray r(origin, direction);

  vec3 point = r.point_at_parameter(2.0f);

  EXPECT_FLOAT_EQ(point.x(), 3e-9f);
  EXPECT_FLOAT_EQ(point.y(), 3e-9f);
  EXPECT_FLOAT_EQ(point.z(), 3e-9f);
}

TEST(RayTest, TestRayWithNegativeNumbers) {
  vec3 origin(-1.0f, -2.0f, -3.0f);
  vec3 direction(-4.0f, -5.0f, -6.0f);
  ray r(origin, direction);

  vec3 point = r.point_at_parameter(2.0f);

  EXPECT_FLOAT_EQ(point.x(), -9.0f);
  EXPECT_FLOAT_EQ(point.y(), -12.0f);
  EXPECT_FLOAT_EQ(point.z(), -15.0f);
}

TEST(RayTest, TestRayWithMixOfPositiveAndNegativeNumbers) {
  vec3 origin(-1.0f, 2.0f, -3.0f);
  vec3 direction(4.0f, -5.0f, 6.0f);
  ray r(origin, direction);

  vec3 point = r.point_at_parameter(2.0f);

  EXPECT_FLOAT_EQ(point.x(), 7.0f);
  EXPECT_FLOAT_EQ(point.y(), -8.0f);
  EXPECT_FLOAT_EQ(point.z(), 9.0f);
}