#include "catch.hpp"

#include "unit/velocity.hpp"

extern int testNumber;

namespace velocity = unit::velocity;

SCENARIO( "make function", "[unit], [velocity]" ) {
  GIVEN( "a physical velocity value" ){
    WHEN( "constructing a velocity::Value with a"
          " valid string via the make function" ) {
      THEN( "the Velocity has been converted to the correct unit" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] No Errors Expected";
         REQUIRE( Approx(.01) ==
                  velocity::make( 1.0, "centimeter per second" ).value() );
         REQUIRE( Approx(1) ==
                  velocity::make( 1.0, "meter per second" ).value() );
         REQUIRE( Approx(0.27777777777) ==
                  velocity::make( 1.0, "kilometer per hour" ).value() );
      }
    }

    WHEN( "constructing a velocity::Value with an"
          " invalid string via the make function" ) {
      THEN( "the function will throw" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] Errors Expected";
        REQUIRE_THROWS( velocity::make( 1.0 , "foo" ) );
      }
    }
    
    WHEN( "constructing a velocity Value with a"
          " valid enum via the make function" ) {
      THEN( "the Velocity has been converted to the correct unit" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] No Errors Expected";

         REQUIRE( Approx(.01) ==
                  velocity::make( 1.0, velocity::Unit::centimeterPerSecond ).value() );
         REQUIRE( Approx(1) ==
                  velocity::make( 1.0, velocity::Unit::meterPerSecond ).value() );
         REQUIRE( Approx(0.27777777777) ==
                  velocity::make( 1.0, velocity::Unit::kilometerPerHour ).value() );         
      }
    }

    WHEN( "constructing a velocity Value with an"
          " invalid enum via the make function" ) {
      THEN( "the Velocity has been converted to the correct unit" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] Errors Expected";
        auto sillyUnit = static_cast< velocity::Unit >( 1024 );
        REQUIRE_THROWS( velocity::make( 1.0, sillyUnit ) );
      }
    }
  }
}
