#define CATCH_CONFIG_RUNNER

#include "catch.hpp"

#include "unit/length.hpp"

int testNumber = 0;

int main( int argc, const char* argv[] )
{
  LOG(INFO) << "";
  LOG(INFO) << " Length Tests";
  LOG(INFO) << "======================";
  int result = Catch::Session().run( argc, argv );
  LOG(INFO) << "Length Tests Complete!";
  return result;
}

namespace length = unit::length;

SCENARIO("Value constructor ", "[unit], [length], [Value], [ctor]") {

  LOG(INFO) << "Test " << ++testNumber << ": [construction] No Errors Expected";

  GIVEN("a physical length value"){

    WHEN("constructing a valid Length with the constructor") {

      THEN("the constructor should convert to the correct unit") {

        REQUIRE( Approx(100) == length::Value( 1.0 * length::m ).value() );
        REQUIRE( Approx(1) == length::Value( 1.0 * length::cm ).value() );
        REQUIRE( Approx(0.1) == length::Value( 1.0 * length::mm ).value() );
        REQUIRE( Approx(1e-4) == length::Value( 1.0 * length::um ).value() );
        REQUIRE( Approx(1e-7) == length::Value( 1.0 * length::nm ).value() );
      }
    }
  }
}
