#include "List.hpp"
#include "circle.hpp"

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>

TEST_CASE (" create list ", "[create_list]")
{
  List<int> testList;

  REQUIRE (testList.size() == 0);
  REQUIRE (testList.empty());
}

TEST_CASE ("add an element with push_front", "[modifiers]")
{
  List<int> list;
  list.push_front(42);
  REQUIRE (42 == list.front());
  list.push_front(5);
  REQUIRE (5 == list.front());
  list.push_front(9);
  REQUIRE (9 == list.front());
  REQUIRE (42 == list.back());
}
TEST_CASE ("add an element with push_back", "[modifiers]")
{
  List<int> list;
  list.push_back(0);
  REQUIRE (0 == list.back());
  list.push_back(5);
  REQUIRE (5 == list.back());
  list.push_back(65);
  REQUIRE (65 == list.back());
  REQUIRE (0 == list.front());
}
TEST_CASE ("remove an element with pop_front", "[modifiers]")
{
  List<int> list;
  list.push_front(42);
  list.push_front(5);
  list.push_front(3);
  list.pop_front();
  REQUIRE (5 == list.front());
  list.pop_front();
  REQUIRE (42 == list.front());
  list.pop_front();
  REQUIRE (0 == list.size());
}
TEST_CASE ("remove an element with pop_back", "[modifiers]")
{
  List<int> list;
  list.push_front(42);
  list.push_front(5);
  list.push_front(3);
  list.pop_back();
  REQUIRE (3 == list.front());
  REQUIRE (5 == list.back());
  list.pop_back();
  REQUIRE (3 == list.front());
  list.pop_back();
  REQUIRE (0 == list.size());
}
TEST_CASE ("should be empty after clearing", "[modifiers]")
{
  List<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  list.clear();
  REQUIRE (list.empty());
}
TEST_CASE ("iterator", "[iterator]")
{
  List<Circle> circle_list;
  circle_list.push_back({{400.f, 400.f}, 100.f, {0.f,0.5f,1.0f}, {0.f,1.f,1.0f}, "Niña"});
  circle_list.push_back({{120.f, 600.f}, 50.f, {0.2f,0.6f,0.6f}, {1.f,1.f,1.f}, "Pinta"});
  circle_list.push_back({{90.f, 500.f}, 80.f, {0.f,0.f,0.f}, {1.f,1.f,1.f}, "Santa María"});
  auto c_it = circle_list.begin();
  std :: cout << "Der Radius des 1. Circles in der Liste ist: " << c_it -> get_radius() << std::endl;
}
TEST_CASE ("should be an empty range after default construction", "[iterators]")
{
  List<int> list ;
  auto b = list.begin();
  auto e = list.end();
  REQUIRE (b == e);
}
TEST_CASE ("provide access to the first element with begin", "[iterators]")
{
  List<int> list ;
  list.push_front (42);
  REQUIRE (42 == *list.begin());
}

int main (int argc , char * argv [])
{
  return Catch::Session().run(argc, argv);
}