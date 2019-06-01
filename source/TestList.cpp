#include "List.hpp"

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

TEST_CASE (" create list ", "[create_list]")
{
  List<int> testList;

  REQUIRE (testList.size() == 0);
  REQUIRE (testList.empty());
}

TEST_CASE ("add an element with push_front ", "[modifiers1]")
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
TEST_CASE ("add an element with push_back ", "[modifiers2]")
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
TEST_CASE ("remove an element with pop_front ", "[modifiers3]")
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
TEST_CASE ("remove an element with pop_back ", "[modifiers4]")
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

int main (int argc , char * argv [])
{
  return Catch::Session().run(argc, argv);
}