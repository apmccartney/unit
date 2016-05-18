#include "catch.hpp"

#include "unit/volume.hpp"

extern int testNumber;

namespace volume = unit::volume;

SCENARIO( "make function", "[unit], [volume]" ) {
  GIVEN( "a physical volume value" ){
    WHEN( "constructing a volume::Value with a"
          " valid string via the make function" ) {
      THEN( "the Volume has been converted to the correct unit" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] No Errors Expected";
        REQUIRE( Approx(1E6) == volume::make( 1.0 , "m3" ).value() );
        REQUIRE( Approx(1) == volume::make( 1.0 , "cm3" ).value() );
        REQUIRE( Approx(1E-3) == volume::make( 1.0 , "mm3" ).value() );
        REQUIRE( Approx(1e-13) == volume::make( 1.0 , "um3" ).value() );
        REQUIRE( Approx(1e-21) == volume::make( 1.0 , "nm3" ).value() );
      }
    }

    WHEN( "constructing a volume::Value with an"
          " invalid string via the make function" ) {
      THEN( "the function will throw" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] Errors Expected";
        REQUIRE_THROWS( volume::make( 1.0 , "foo" ) );
      }
    }
    
    WHEN( "constructing a volume Value with a"
          " valid enum via the make function" ) {
      THEN( "the Volume has been converted to the correct unit" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] No Errors Expected";
        REQUIRE( Approx(1E6) ==
                 volume::make( 1.0, volume::Unit::cubicMeter ).value() );
        REQUIRE( Approx(1) ==
                 volume::make( 1.0, volume::Unit::cubicCentimeter ).value() );
        REQUIRE( Approx(1E-3) ==
                 volume::make( 1.0, volume::Unit::cubicMillimeter ).value() );
        REQUIRE( Approx(1e-12) ==
                 volume::make( 1.0, volume::Unit::cubicMicrometer ).value() );
        REQUIRE( Approx(1e-21) ==
                 volume::make( 1.0, volume::Unit::cubicNanometer ).value() );
      }
    }

    WHEN( "constructing a volume Value with an"
          " invalid enum via the make function" ) {
      THEN( "the Volume has been converted to the correct unit" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] Errors Expected";
        auto sillyUnit = static_cast< volume::Unit >( 1024 );
        REQUIRE_THROWS( volume::make( 1.0, sillyUnit ) );
      }
    }
  }
}
