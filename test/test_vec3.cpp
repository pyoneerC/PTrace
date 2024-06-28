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

#include "../math/vec3.h"
#include "gtest/gtest.h"
#include <cmath>

TEST(Vec3Test, TestVec3Addition) {
  vec3 v1(1.0f, 2.0f, 3.0f);
  vec3 v2(4.0f, 5.0f, 6.0f);
  vec3 v3 = v1 + v2;

  EXPECT_FLOAT_EQ(v3.x(), 5.0f);
  EXPECT_FLOAT_EQ(v3.y(), 7.0f);
  EXPECT_FLOAT_EQ(v3.z(), 9.0f);

  // Test addition with zero
  vec3 v4(0.0f, 0.0f, 0.0f);
  vec3 v5 = v1 + v4;

  EXPECT_FLOAT_EQ(v5.x(), v1.x());
  EXPECT_FLOAT_EQ(v5.y(), v1.y());
  EXPECT_FLOAT_EQ(v5.z(), v1.z());
}

TEST(Vec3Test, TestVec3Subtraction) {
  vec3 v1(1.0f, 2.0f, 3.0f);
  vec3 v2(4.0f, 5.0f, 6.0f);
  vec3 v3 = v1 - v2;

  EXPECT_FLOAT_EQ(v3.x(), -3.0f);
  EXPECT_FLOAT_EQ(v3.y(), -3.0f);
  EXPECT_FLOAT_EQ(v3.z(), -3.0f);

  // Test subtraction with zero
  vec3 v4(0.0f, 0.0f, 0.0f);
  vec3 v5 = v1 - v4;

  EXPECT_FLOAT_EQ(v5.x(), v1.x());
  EXPECT_FLOAT_EQ(v5.y(), v1.y());
  EXPECT_FLOAT_EQ(v5.z(), v1.z());
}

TEST(Vec3Test, TestVec3Multiplication) {
  vec3 v1(1.0f, 2.0f, 3.0f);
  vec3 v2 = v1 * 2.0f;

  EXPECT_FLOAT_EQ(v2.x(), 2.0f);
  EXPECT_FLOAT_EQ(v2.y(), 4.0f);
  EXPECT_FLOAT_EQ(v2.z(), 6.0f);
}

TEST(Vec3Test, TestVec3Division) {
  vec3 v1(2.0f, 4.0f, 6.0f);
  vec3 v2 = v1 / 2.0f;

  EXPECT_FLOAT_EQ(v2.x(), 1.0f);
  EXPECT_FLOAT_EQ(v2.y(), 2.0f);
  EXPECT_FLOAT_EQ(v2.z(), 3.0f);
}

TEST(Vec3Test, TestLength) {
  vec3 v(3.0f, 4.0f, 0.0f);
  EXPECT_FLOAT_EQ(v.length(), 5.0f);
  vec3 v2(0.0f, 0.0f, 0.0f);
  EXPECT_FLOAT_EQ(v2.length(), 0.0f);
  vec3 v3(1.0f, 1.0f, 1.0f);
  EXPECT_FLOAT_EQ(v3.length(), 1.7320508075688772f);
}

TEST(Vec3Test, TestSquaredLength) {
  vec3 v(3.0f, 4.0f, 0.0f);
  EXPECT_FLOAT_EQ(v.squared_length(), 25.0f);
  vec3 v2(0.0f, 0.0f, 0.0f);
  EXPECT_FLOAT_EQ(v2.squared_length(), 0.0f);
  vec3 v3(1.0f, 1.0f, 1.0f);
  EXPECT_FLOAT_EQ(v3.squared_length(), 3.0f);
}

TEST(Vec3Test, TestMakeUnitVector) {
  vec3 v(3.0f, 4.0f, 0.0f);
  v.make_unit_vector();

  EXPECT_FLOAT_EQ(v.length(), 1.0f);
  EXPECT_FLOAT_EQ(v.x(), 3.0f / 5.0f);
  EXPECT_FLOAT_EQ(v.y(), 4.0f / 5.0f);
  EXPECT_FLOAT_EQ(v.z(), 0.0f);
}

TEST(Vec3Test, TestUnaryMinus) {
  vec3 v(3.0f, 4.0f, 0.0f);
  vec3 v2 = -v;

  EXPECT_FLOAT_EQ(v2.x(), -3.0f);
  EXPECT_FLOAT_EQ(v2.y(), -4.0f);
  EXPECT_FLOAT_EQ(v2.z(), 0.0f);
}

TEST(Vec3Test, TestIndexOperator) {
  vec3 v(3.0f, 4.0f, 0.0f);

  EXPECT_FLOAT_EQ(v[0], 3.0f);
  EXPECT_FLOAT_EQ(v[1], 4.0f);
  EXPECT_FLOAT_EQ(v[2], 0.0f);
}

TEST(Vec3Test, TestCompoundAddition) {
  vec3 v1(1.0f, 2.0f, 3.0f);
  vec3 v2(4.0f, 5.0f, 6.0f);
  v1 += v2;

  EXPECT_FLOAT_EQ(v1.x(), 5.0f);
  EXPECT_FLOAT_EQ(v1.y(), 7.0f);
  EXPECT_FLOAT_EQ(v1.z(), 9.0f);
}

TEST(Vec3Test, TestCompoundSubtraction) {
  vec3 v1(1.0f, 2.0f, 3.0f);
  vec3 v2(4.0f, 5.0f, 6.0f);
  v1 -= v2;

  EXPECT_FLOAT_EQ(v1.x(), -3.0f);
  EXPECT_FLOAT_EQ(v1.y(), -3.0f);
  EXPECT_FLOAT_EQ(v1.z(), -3.0f);
}

TEST(Vec3Test, TestCompoundMultiplication) {
  vec3 v1(1.0f, 2.0f, 3.0f);
  vec3 v2(4.0f, 5.0f, 6.0f);
  v1 *= v2;

  EXPECT_FLOAT_EQ(v1.x(), 4.0f);
  EXPECT_FLOAT_EQ(v1.y(), 10.0f);
  EXPECT_FLOAT_EQ(v1.z(), 18.0f);
}

TEST(Vec3Test, TestCompoundDivision) {
  vec3 v1(2.0f, 4.0f, 6.0f);
  vec3 v2(2.0f, 2.0f, 2.0f);
  v1 /= v2;

  EXPECT_FLOAT_EQ(v1.x(), 1.0f);
  EXPECT_FLOAT_EQ(v1.y(), 2.0f);
  EXPECT_FLOAT_EQ(v1.z(), 3.0f);
}

TEST(Vec3Test, TestVec3Equality) {
  vec3 v1(1.0f, 2.0f, 3.0f);
  vec3 v2(1.0f, 2.0f, 3.0f);
  vec3 v3(4.0f, 5.0f, 6.0f);

  EXPECT_TRUE(v1 == v2);
  EXPECT_FALSE(v1 == v3);
}

TEST(Vec3Test, TestVec3Inequality) {
  vec3 v1(1.0f, 2.0f, 3.0f);
  vec3 v2(1.0f, 2.0f, 3.0f);
  vec3 v3(4.0f, 5.0f, 6.0f);

  EXPECT_FALSE(v1 != v2);
  EXPECT_TRUE(v1 != v3);
}

TEST(Vec3Test, TestVec3LessThan) {
  vec3 v1(1.0f, 2.0f, 3.0f);
  vec3 v2(4.0f, 5.0f, 6.0f);

  EXPECT_TRUE(v1 < v2);
  EXPECT_FALSE(v2 < v1);
}

TEST(Vec3Test, TestVec3GreaterThan) {
  vec3 v1(1.0f, 2.0f, 3.0f);
  vec3 v2(4.0f, 5.0f, 6.0f);

  EXPECT_TRUE(v2 > v1);
  EXPECT_FALSE(v1 > v2);
}

TEST(Vec3Test, TestVec3LessThanOrEqual) {
  vec3 v1(1.0f, 2.0f, 3.0f);
  vec3 v2(4.0f, 5.0f, 6.0f);
  vec3 v3(1.0f, 2.0f, 3.0f);

  EXPECT_TRUE(v1 <= v2);
  EXPECT_TRUE(v1 <= v3);
  EXPECT_FALSE(v2 <= v1);
}

TEST(Vec3Test, TestVec3GreaterThanOrEqual) {
  vec3 v1(1.0f, 2.0f, 3.0f);
  vec3 v2(4.0f, 5.0f, 6.0f);
  vec3 v3(1.0f, 2.0f, 3.0f);

  EXPECT_TRUE(v2 >= v1);
  EXPECT_TRUE(v1 >= v3);
  EXPECT_FALSE(v1 >= v2);
}

TEST(Vec3Test, TestVec3Negation) {
  vec3 v(1.0f, 2.0f, 3.0f);
  vec3 v2 = !v;

  EXPECT_FLOAT_EQ(v2.x(), -1.0f);
  EXPECT_FLOAT_EQ(v2.y(), -2.0f);
  EXPECT_FLOAT_EQ(v2.z(), -3.0f);
}

TEST(Vec3Test, TestDefaultConstructor) {
  vec3 v;

  EXPECT_FLOAT_EQ(v.x(), 0.0f);
  EXPECT_FLOAT_EQ(v.y(), 0.0f);
  EXPECT_FLOAT_EQ(v.z(), 0.0f);
}

TEST(Vec3Test, TestParameterizedConstructor) {
  vec3 v(1.0f, 2.0f, 3.0f);

  EXPECT_FLOAT_EQ(v.x(), 1.0f);
  EXPECT_FLOAT_EQ(v.y(), 2.0f);
  EXPECT_FLOAT_EQ(v.z(), 3.0f);
}

TEST(Vec3Test, TestCopyConstructor) {
  vec3 v1(1.0f, 2.0f, 3.0f);
  vec3 v2(v1);

  EXPECT_FLOAT_EQ(v2.x(), 1.0f);
  EXPECT_FLOAT_EQ(v2.y(), 2.0f);
  EXPECT_FLOAT_EQ(v2.z(), 3.0f);
}

TEST(Vec3Test, TestAssignmentOperator) {
  vec3 v1(1.0f, 2.0f, 3.0f);
  vec3 v2;
  v2 = v1;

  EXPECT_FLOAT_EQ(v2.x(), 1.0f);
  EXPECT_FLOAT_EQ(v2.y(), 2.0f);
  EXPECT_FLOAT_EQ(v2.z(), 3.0f);
}

TEST(Vec3Test, TestVec3MultiplicationByScalar) {
  vec3 v(1.0f, 2.0f, 3.0f);
  vec3 v2 = v * 2.0f;

  EXPECT_FLOAT_EQ(v2.x(), 2.0f);
  EXPECT_FLOAT_EQ(v2.y(), 4.0f);
  EXPECT_FLOAT_EQ(v2.z(), 6.0f);
}

TEST(Vec3Test, TestVec3DivisionByScalar) {
  vec3 v(2.0f, 4.0f, 6.0f);
  vec3 v2 = v / 2.0f;

  EXPECT_FLOAT_EQ(v2.x(), 1.0f);
  EXPECT_FLOAT_EQ(v2.y(), 2.0f);
  EXPECT_FLOAT_EQ(v2.z(), 3.0f);

  vec3 v3(1.0f, 2.0f, 3.0f);
  vec3 v4 = v3 / 3.0f;

  EXPECT_FLOAT_EQ(v4.x(), 1.0f / 3.0f);
  EXPECT_FLOAT_EQ(v4.y(), 2.0f / 3.0f);
  EXPECT_FLOAT_EQ(v4.z(), 3.0f / 3.0f);

  vec3 v5(1.0f, 2.0f, 3.0f);
  vec3 v6 = v5 / 1.0f;

  EXPECT_FLOAT_EQ(v6.x(), 1.0f);
  EXPECT_FLOAT_EQ(v6.y(), 2.0f);
  EXPECT_FLOAT_EQ(v6.z(), 3.0f);
}

TEST(Vec3Test, TestVec3DotProduct) {
  vec3 v1(1.0f, 2.0f, 3.0f);
  vec3 v2(4.0f, 5.0f, 6.0f);

  EXPECT_FLOAT_EQ(dot(v1, v2), 32.0f);

  vec3 v3(1.0f, 0.0f, 0.0f);
  vec3 v4(0.0f, 1.0f, 0.0f);

  EXPECT_FLOAT_EQ(dot(v3, v4), 0.0f);

  vec3 v5(1.0f, 2.0f, 3.0f);
  vec3 v6(9.0f, 8.0f, 7.0f);

  EXPECT_FLOAT_EQ(dot(v5, v6), 46.0f);
}

TEST(Vec3Test, TestVec3RGBAccessors) {
  vec3 v(1.0f, 2.0f, 3.0f);

  EXPECT_FLOAT_EQ(v.r(), 1.0f);
  EXPECT_FLOAT_EQ(v.g(), 2.0f);
  EXPECT_FLOAT_EQ(v.b(), 3.0f);
}

TEST(Vec3Test, TestVec3CrossProduct) {
  vec3 v1(1.0f, 0.0f, 0.0f);
  vec3 v2(0.0f, 1.0f, 0.0f);
  vec3 v3 = cross(v1, v2);

  EXPECT_FLOAT_EQ(v3.x(), 0.0f);
  EXPECT_FLOAT_EQ(v3.y(), 0.0f);
  EXPECT_FLOAT_EQ(v3.z(), 1.0f);

  // Check orthogonality
  EXPECT_FLOAT_EQ(dot(v1, v3), 0.0f);
  EXPECT_FLOAT_EQ(dot(v2, v3), 0.0f);

  vec3 v4(1.0f, 2.0f, 3.0f);
  vec3 v5(4.0f, 5.0f, 6.0f);
  vec3 v6 = cross(v4, v5);

  EXPECT_FLOAT_EQ(v6.x(), -3.0f);
  EXPECT_FLOAT_EQ(v6.y(), 6.0f);
  EXPECT_FLOAT_EQ(v6.z(), -3.0f);

  EXPECT_FLOAT_EQ(dot(v4, v6), 0.0f);
  EXPECT_FLOAT_EQ(dot(v5, v6), 0.0f);
}

TEST(Vec3Test, TestVec3Normalization) {
  vec3 v(1.0f, 2.0f, 3.0f);
  v.make_unit_vector();

  EXPECT_FLOAT_EQ(v.length(), 1.0f);

  float magnitude = std::sqrt(1.0f + 4.0f + 9.0f); // sqrt(x^2 + y^2 + z^2)
  EXPECT_FLOAT_EQ(v.x(), 1.0f / magnitude);
  EXPECT_FLOAT_EQ(v.y(), 2.0f / magnitude);
  EXPECT_FLOAT_EQ(v.z(), 3.0f / magnitude);
}