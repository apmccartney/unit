#include "catch.hpp"

#include "unit/length.hpp"

extern int testNumber;

namespace length = unit::length;

SCENARIO( "make function", "[unit], [length]" ) {
  GIVEN( "a physical length value" ){
    WHEN( "constructing a length::Value with a"
          " valid string via the make function" ) {
      THEN( "the Length has been converted to the correct unit" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] No Errors Expected";
        REQUIRE( Approx(100) == length::make( 1.0 , "m" ).value() );
        REQUIRE( Approx(1) == length::make( 1.0 , "cm" ).value() );
        REQUIRE( Approx(0.1) == length::make( 1.0 , "mm" ).value() );
        REQUIRE( Approx(1e-4) == length::make( 1.0 , "um" ).value() );
        REQUIRE( Approx(1e-7) == length::make( 1.0 , "nm" ).value() );
      }
    }

    WHEN( "constructing a length::Value with an"
          " invalid string via the make function" ) {
      THEN( "the function will throw" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] Errors Expected";
        REQUIRE_THROWS( length::make( 1.0 , "foo" ) );
      }
    }
    
    WHEN( "constructing a length Value with a"
          " valid enum via the make function" ) {
      THEN( "the Length has been converted to the correct unit" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] No Errors Expected";
        REQUIRE( Approx(100) ==
                 length::make( 1.0, length::Unit::meter ).value() );
        REQUIRE( Approx(1) ==
                 length::make( 1.0, length::Unit::centimeter ).value() );
        REQUIRE( Approx(0.1) ==
                 length::make( 1.0, length::Unit::millimeter ).value() );
        REQUIRE( Approx(1e-4) ==
                 length::make( 1.0, length::Unit::micrometer ).value() );
        REQUIRE( Approx(1e-7) ==
                 length::make( 1.0, length::Unit::nanometer ).value() );
      }
    }

    WHEN( "constructing a length Value with an"
          " invalid enum via the make function" ) {
      THEN( "the Length has been converted to the correct unit" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] Errors Expected";
        auto sillyUnit = static_cast< length::Unit >( 1024 );
        REQUIRE_THROWS( length::make( 1.0, sillyUnit ) );
      }
    }
  }
}
