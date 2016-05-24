#include "catch.hpp"

#include "unit/velocity.hpp"

extern int testNumber;

using namespace unit;

SCENARIO( "make function", "[unit], [velocity]" ) {
  GIVEN( "a physical velocity value" ){
    WHEN( "constructing a velocity::Value with a"
          " valid string via the make function" ) {
      THEN( "the Velocity has been converted to the correct unit" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] No Errors Expected";
         REQUIRE( Approx(.01) ==
                  velocity::make( 1.0, "cm/s", m_per_s ).value() );
         REQUIRE( Approx(1) ==
                  velocity::make( 1.0, "m/s", m_per_s ).value() );
         REQUIRE( Approx(0.27777777777) ==
                  velocity::make( 1.0, "km/hour", m_per_s ).value() );
      }
    }

    WHEN( "constructing a velocity::Value with an"
          " invalid string via the make function" ) {
      THEN( "the function will throw" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] Errors Expected";
        REQUIRE_THROWS( velocity::make( 1.0 , "foo", m_per_s ) );
      }
    }    
  }
}

