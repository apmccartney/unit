#define CATCH_CONFIG_RUNNER

#include "catch.hpp"

#include "unit/volume.hpp"

int testNumber = 0;

int main( int argc, const char* argv[] )
{
  LOG(INFO) << "";
  LOG(INFO) << " Volume Tests";
  LOG(INFO) << "======================";
  int result = Catch::Session().run( argc, argv );
  LOG(INFO) << "Volume Tests Complete!";
  return result;
}

using namespace unit;

SCENARIO("Value constructor ", "[unit], [volume], [ctor]") {

  LOG(INFO) << "Test " << ++testNumber << ": [construction] No Errors Expected";

  GIVEN("a physical volume value"){

    WHEN("constructing a valid Volume with the constructor") {

      THEN("the constructor should convert to the correct unit") {

        REQUIRE( Approx(1E6) == Quantity< CubicCentimeter >( 1.0 * volume::m3 ).value() );
        REQUIRE( Approx(1) == Quantity< CubicCentimeter >( 1.0 * volume::cm3 ).value() );
        REQUIRE( Approx(1E-3) == Quantity< CubicCentimeter >( 1.0 * volume::mm3 ).value() );
        REQUIRE( Approx(1e-12) == Quantity< CubicCentimeter >( 1.0 * volume::um3 ).value() );
        REQUIRE( Approx(1e-21) == Quantity< CubicCentimeter >( 1.0 * volume::nm3 ).value() );
      }
    }
  }
}
