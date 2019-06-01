#include "vec2.hpp"

#include <iostream>


Vec2& Vec2::operator+=(Vec2 const& v) {
  x += v.x;
  y += v.y;
  return *this;
}

Vec2& Vec2::operator-=(Vec2 const& v) {
  x -= v.x;
  y -= v.y;
  return *this;
}

Vec2& Vec2::operator*=(float s) {
  x *= s;
  y *= s;
  return *this;
}

Vec2& Vec2::operator/=(float s) {
  if (s == 0) {
    std::cout << "Not able to divide between 0" << std::endl;
    std::cout << std::endl;
    return *this;
  }
  x /= s;
  y /= s;
  return *this;
}

Vec2 operator+(Vec2 const& u, Vec2 const& v) {
  return Vec2(u) += v;
};

Vec2 operator-(Vec2 const& u, Vec2 const& v) {
  return Vec2(u) -= v;
};

Vec2 operator*(Vec2 const& v, float s) {
  return Vec2(v) *= s;
};

Vec2 operator/(Vec2 const& v, float s) {
  return Vec2(v) /= s;
};

Vec2 operator*(float s, Vec2 const& v) {
  return v * s;
};

