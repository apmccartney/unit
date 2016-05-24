#include "catch.hpp"

#include "unit/time.hpp"

extern int testNumber;

using namespace unit;

SCENARIO( "make function", "[unit], [time]" ) {
  GIVEN( "a physical time value" ){
    WHEN( "constructing a time::Value with a"
          " valid string via the make function" ) {
      THEN( "the Time has been converted to the correct unit" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] No Errors Expected";
        REQUIRE( Approx(1) == time::make( 1.0 , "s", s ).value() );
        REQUIRE( Approx(1E-3) == time::make( 1.0 , "ms", s ).value() );
        REQUIRE( Approx(1E-6) == time::make( 1.0 , "us", s ).value() );
        REQUIRE( Approx(1e-9) == time::make( 1.0 , "ns", s ).value() );
        REQUIRE( Approx(60) == time::make( 1.0 , "min", s ).value() );
        REQUIRE( Approx(3600) == time::make( 1.0 , "hour", s ).value() );
        REQUIRE( Approx(86400) == time::make( 1.0 , "d", s ).value() );
        REQUIRE( Approx(31556926.08) == time::make( 1.0 , "y", s ).value() );
      }
    }

    WHEN( "constructing a time::Value with an"
          " invalid string via the make function" ) {
      THEN( "the function will throw" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] Errors Expected";
        REQUIRE_THROWS( time::make( 1.0 , "foo", s ) );
      }
    }
  }
}
