#include "catch.hpp"

#include "unit/area.hpp"

extern int testNumber;

namespace area = unit::area;

SCENARIO( "make function", "[unit], [area]" ) {
  GIVEN( "a physical area value" ){
    WHEN( "constructing a area::Value with a"
          " valid string via the make function" ) {
      THEN( "the Area has been converted to the correct unit" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] No Errors Expected";
        REQUIRE( Approx(1E4) == area::make( 1.0 , "m2" ).value() );
        REQUIRE( Approx(1) == area::make( 1.0 , "cm2" ).value() );
        REQUIRE( Approx(1E-2) == area::make( 1.0 , "mm2" ).value() );
        REQUIRE( Approx(1e-8) == area::make( 1.0 , "um2" ).value() );
        REQUIRE( Approx(1e-14) == area::make( 1.0 , "nm2" ).value() );
      }
    }

    WHEN( "constructing a area::Value with an"
          " invalid string via the make function" ) {
      THEN( "the function will throw" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] Errors Expected";
        REQUIRE_THROWS( area::make( 1.0 , "foo" ) );
      }
    }    
  }
}
