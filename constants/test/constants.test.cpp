#define CATCH_CONFIG_RUNNER

#include "catch.hpp"

#include "unit/constants.hpp"

int testNumber = 0;

namespace constants = unit::constants;

int main( int argc, const char* argv[] )
{
  LOG(INFO) << "";
  LOG(INFO) << " Constants Tests";
  LOG(INFO) << "======================";
  int result = Catch::Session().run( argc, argv );
  LOG(INFO) << "Constants Tests Complete!";
  return result;
}

namespace length = unit::length;

SCENARIO("Constants ", "[unit], [constants]") {
  GIVEN("a collection of physical constants"){
    WHEN("queried for their value") {
      THEN("the value will match expectations") {
        REQUIRE( Approx(299792458.0) /* m/s */== constants::lightSpeed.value() );
      }
    }
  }
}
