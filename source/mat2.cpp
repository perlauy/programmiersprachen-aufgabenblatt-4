#include "vec2.hpp"
#include "mat2.hpp"

#include <cmath>
#include <iostream>


Mat2& Mat2::operator*=(Mat2 const& m) {
  Mat2 temp{*this};

  e_00 = temp.e_00*m.e_00 + temp.e_01*m.e_10;
  e_01 = temp.e_00*m.e_01 + temp.e_01*m.e_11;
  e_10 = temp.e_10*m.e_00 + temp.e_11*m.e_10;
  e_11 = temp.e_10*m.e_01 + temp.e_11*m.e_11;
  
  return *this;
}

float Mat2::det() const {
  return e_00 * e_11 - e_01 * e_10;
};


Mat2 operator*(Mat2 const& m1, Mat2 const& m2) {
  return Mat2(m1) *= m2;
};

Vec2 operator*(Mat2 const& m, Vec2 const& v) {
  Vec2 temp{m.e_00 * v.x + m.e_01*v.y, m.e_10 * v.x + m.e_11 * v.y};
  return temp;
};

Vec2 operator*(Vec2 const& v, Mat2 const& m) {
  Vec2 temp{m.e_00 * v.x + m.e_01*v.y, m.e_10 * v.x + m.e_11 * v.y};
  return temp;
};

Mat2 inverse(Mat2 const& m) {
  if (m.det() != 0) {
    float inv_det = 1 / m.det();
    Mat2 temp{inv_det * m.e_11, inv_det * -m.e_01, inv_det * -m.e_10, inv_det * m.e_00};
    return temp;
  } else {
    std::cout << "This matrix is not inversable!" << std::endl;
    std::cout << std::endl;
    return m;
  }
};

Mat2 transpose(Mat2 const& m) {
  Mat2 temp{m.e_00, m.e_10, m.e_01, m.e_11};
  return temp;
};

Mat2 make_rotation_mat2(float phi) {
  // phi in radians
  Mat2 matrix{cos(phi), -sin(phi), sin(phi), cos(phi)};
  return matrix;
};