#include "List.hpp"

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

TEST_CASE (" test ", "[test]")
{
  List<int> testList;

  REQUIRE (testList.size() == 0);
  REQUIRE (testList.empty());
}

int main (int argc , char * argv [])
{

  

  return Catch::Session().run(argc, argv);
}