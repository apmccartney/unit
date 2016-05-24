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

using namespace unit;

SCENARIO("ctor", "[unit], [length], [ctor]") {

  LOG(INFO) << "Test " << ++testNumber << ": [construction] No Errors Expected";

  GIVEN("a physical length value"){

    WHEN("constructing a valid Length with the constructor") {

      THEN("the constructor should convert to the correct unit") {

        REQUIRE( Approx(100) == Quantity< Centimeter >( 1.0 * m ).value() );
        REQUIRE( Approx(1) == Quantity< Centimeter >( 1.0 * cm ).value() );
        REQUIRE( Approx(0.1) == Quantity< Centimeter >( 1.0 * mm ).value() );
        REQUIRE( Approx(1e-4) == Quantity< Centimeter >( 1.0 * um ).value() ); 
        REQUIRE( Approx(1e-7) == Quantity< Centimeter >( 1.0 * nm ).value() ); 
      }
    }
  }
}
