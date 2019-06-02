#include "List.hpp"
#include "circle.hpp"

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <vector>
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
  list.push_front(42);
  REQUIRE (42 == *list.begin());
}
TEST_CASE ("prove two lists are equal", "[equal]")
{
  List<int> list1;
  list1.push_front(4);
  list1.push_front(5);
  list1.push_front(6);
  List<int> list2;
  list2.push_front(4);
  list2.push_front(5);
  list2.push_front(6);
  REQUIRE (list1 == list2);
  List<int> list3;
  list3.push_front(5);
  list3.push_front(6);
  list3.push_front(7);
  REQUIRE (list1 != list3);
}

TEST_CASE ("copy constructor", "[constructor]")
{
  List<int> list ;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  List<int> list2{list};
  REQUIRE (list == list2);
  REQUIRE (list.front() == list2.front());
}
TEST_CASE ("insert new node", "[modifiers]")
{
  List<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  list.insert(list.begin().next(), 8);
  REQUIRE (*list.begin().next() == 8);
  list.insert(list.begin(), 5);
  REQUIRE (list.front() == 5);
  list.insert(list.end(), 6);
  REQUIRE (list.back() == 6);
}

TEST_CASE ("move constructor", "[constructor]")
{
  List<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  List<int> list2 = std::move(list);
  REQUIRE (0 == list.size());
  REQUIRE ( list.empty());
  REQUIRE (4 == list2.size());
}

TEST_CASE ("reverse list", "[modifiers]")
{
  List<int> list;
  list.reverse(); //it shouldn't crash
  list.push_front(1);
  
  list.reverse(); //it shouldn't crash
  REQUIRE (list.front() == 1);
  REQUIRE (list.back() == 1);

  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  list.reverse(); //it shouldn't crash
  REQUIRE (list.front() == 1);
  REQUIRE (list.back() == 4);
  REQUIRE (*list.begin().next() == 2);

  //List<int> reversed_list(reverse(list)); //Move constructor needs to be implemented -> 4.13 ^
  List<int> reversed_list = reverse(list); //Changed back to operator=, now implemented
  REQUIRE (reversed_list.front() == 4);
  REQUIRE (reversed_list.back() == 1);
  REQUIRE (*reversed_list.begin().next() == 3);
}

TEST_CASE ("copy with std", "[std_copy]")
{
  List<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  
  std::vector<int> to_vector;
  std::copy(list.begin(), list.end(), std::back_inserter(to_vector));
  REQUIRE (to_vector.front() == 4);
  REQUIRE (to_vector.back() == 1);
  REQUIRE (*(++to_vector.begin()) == 3);
}


TEST_CASE ("initialization list constructor", "[constructor]")
{
  List<int> int_list{9, 5, 38, 100};
  REQUIRE (int_list.front() == 9);
  REQUIRE (int_list.back() == 100);
  REQUIRE (*(++int_list.begin()) == 5);
}

TEST_CASE ("concatenate lists", "[concatenate]")
{
  List<int> int_list = List<int>{1, 2} + List<int>{5, 6};
  REQUIRE (int_list.front() == 1);
  REQUIRE (int_list.back() == 6);
  REQUIRE (*(++int_list.begin()) == 2);

  auto l = List <int >{1 , 2, 3, 4, 5} + List <int >{6 , 7, 8, 9};
}

int main (int argc , char * argv [])
{
  return Catch::Session().run(argc, argv);
}