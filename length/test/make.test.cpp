#include "catch.hpp"

#include "unit/length.hpp"

extern int testNumber;

using namespace unit;

SCENARIO( "make function", "[unit], [length]" ) {
  GIVEN( "a physical length value" ){
    WHEN( "constructing a length::Value with a"
          " valid string via the make function" ) {
      THEN( "the Length has been converted to the correct unit" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] No Errors Expected";
        REQUIRE( Approx(100) == length::make( 1.0 , "m", cm ).value() );
        REQUIRE( Approx(1) == length::make( 1.0 , "cm", cm ).value() );
        REQUIRE( Approx(0.1) == length::make( 1.0 , "mm", cm ).value() );
        REQUIRE( Approx(1e-4) == length::make( 1.0 , "um", cm ).value() );
        REQUIRE( Approx(1e-7) == length::make( 1.0 , "nm", cm ).value() );
      }
    }

    WHEN( "constructing a length::Value with an"
          " invalid string via the make function" ) {
      THEN( "the function will throw" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] Errors Expected";
        REQUIRE_THROWS( length::make( 1.0 , "foo", cm ) );
      }
    }
  }
}
