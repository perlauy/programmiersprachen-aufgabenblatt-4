#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"

#include <string>

class Circle {
  
  public:
              Circle();
              Circle(Circle const& c);
              Circle(Vec2 const& center, float radius, Color const& color, Color const& highlight_color, std::string name);
  
  
    double    circumference() const;
    void      draw() const;
    bool      is_inside(Vec2 point) const;
    std::string get_name() const;
    float     get_radius() const;

  private:
    Vec2  center_;
    float radius_;
    Color color_;
    Color highlight_color_;
    std::string name_;
};

bool operator==(Circle const& c1, Circle const& c2);
bool operator<(Circle const& c1, Circle const& c2);
bool operator>(Circle const& c1, Circle const& c2);

#endif
