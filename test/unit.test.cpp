#define CATCH_CONFIG_RUNNER

#include "catch.hpp"

#include "unit.hpp"

int testNumber = 0;

int main( int argc, const char* argv[] )
{
  LOG(INFO) << "";
  LOG(INFO) << " Unit Tests";
  LOG(INFO) << "======================";
  int result = Catch::Session().run( argc, argv );
  LOG(INFO) << "Unit Tests Complete!";
  return result;
}
