#define CATCH_CONFIG_RUNNER

#include "catch.hpp"

#include "unit/area.hpp"

int testNumber = 0;

int main( int argc, const char* argv[] )
{
  LOG(INFO) << "";
  LOG(INFO) << " Area Tests";
  LOG(INFO) << "======================";
  int result = Catch::Session().run( argc, argv );
  LOG(INFO) << "Area Tests Complete!";
  return result;
}

using namespace unit;

SCENARIO("Value constructor ", "[unit], [area], [ctor]") {

  LOG(INFO) << "Test " << ++testNumber << ": [construction] No Errors Expected";

  GIVEN("a physical area value"){

    WHEN("constructing a valid Area with the constructor") {

      THEN("the constructor should convert to the correct unit") {

        REQUIRE( Approx(10000) == Quantity< SquareCentimeter >( 1.0 * area::m2 ).value() );
        REQUIRE( Approx(1) == Quantity< SquareCentimeter >( 1.0 * area::cm2 ).value() );
        REQUIRE( Approx(0.01) == Quantity< SquareCentimeter >( 1.0 * area::mm2 ).value() );
        REQUIRE( Approx(1e-8) == Quantity< SquareCentimeter >( 1.0 * area::um2 ).value() );
        REQUIRE( Approx(1e-14) == Quantity< SquareCentimeter >( 1.0 * area::nm2 ).value() );
        REQUIRE( Approx(1e-24) == Quantity< SquareCentimeter >( 1.0 * area::b ).value() );
      }
    }
  }
}
