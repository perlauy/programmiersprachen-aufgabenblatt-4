#define _USE_MATH_DEFINES

#include "circle.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"

#include <cmath>
#include <string>
#include <iostream>

Circle::Circle() :
  center_{0.f, 0.f},
  radius_{1.f},
  color_{0.5f,0.5f,0.5f},
  highlight_color_{1.f,1.f,0.f},
  name_{"A circle has no name"}
{}

Circle::Circle(Circle const& c) :
  center_{c.center_},
  radius_{c.radius_},
  color_{c.color_},
  highlight_color_{c.highlight_color_},
  name_{c.name_}
{}

Circle::Circle(Vec2 const& center, float radius, Color const& color, Color const& highlight_color, std::string name) :
  center_{center},
  radius_{radius},
  color_{color},
  highlight_color_{highlight_color},
  name_{name}
{}

double Circle::circumference() const {
  return 2 * radius_ * M_PI;
}

void Circle::draw() const {
  std::cout << "\n\nCircle\n--------------------" << std::endl;
  std::cout << "name: " << name_ << std::endl;
  std::cout << "radius: " << radius_ << std::endl;
  std::cout << "center: " << center_.x << ", " << center_.y << std::endl;

}

bool Circle::is_inside(Vec2 point) const {
  return pow(radius_, 2) > (pow(point.x - center_.x, 2) + pow(point.y - center_.y, 2));
};

std::string Circle::get_name() const {
  return name_;
};

float Circle::get_radius() const {
  return radius_;
}

bool operator==(Circle const& c1, Circle const& c2) {
  return c1.get_radius() == c2.get_radius();
}

bool operator<(Circle const& c1, Circle const& c2) {
  return c1.get_radius() < c2.get_radius();
}

bool operator>(Circle const& c1, Circle const& c2) {
  return c1.get_radius() > c2.get_radius();
}

