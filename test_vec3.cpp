#include "vec3.h"
#include "gtest/gtest.h"

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