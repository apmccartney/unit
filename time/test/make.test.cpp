#include "catch.hpp"

#include "unit/time.hpp"

extern int testNumber;

namespace time_ = unit::time;

SCENARIO( "make function", "[unit], [time]" ) {
  GIVEN( "a physical time value" ){
    WHEN( "constructing a time::Value with a"
          " valid string via the make function" ) {
      THEN( "the Time has been converted to the correct unit" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] No Errors Expected";
        REQUIRE( Approx(1) == time_::make( 1.0 , "s" ).value() );
        REQUIRE( Approx(1E-3) == time_::make( 1.0 , "ms" ).value() );
        REQUIRE( Approx(1E-6) == time_::make( 1.0 , "us" ).value() );
        REQUIRE( Approx(1e-9) == time_::make( 1.0 , "ns" ).value() );
        REQUIRE( Approx(60) == time_::make( 1.0 , "min" ).value() );
        REQUIRE( Approx(3600) == time_::make( 1.0 , "hour" ).value() );
        REQUIRE( Approx(86400) == time_::make( 1.0 , "d" ).value() );
        REQUIRE( Approx(31556926.08) == time_::make( 1.0 , "y" ).value() );
      }
    }

    WHEN( "constructing a time::Value with an"
          " invalid string via the make function" ) {
      THEN( "the function will throw" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] Errors Expected";
        REQUIRE_THROWS( time_::make( 1.0 , "foo" ) );
      }
    }
    
    WHEN( "constructing a time Value with a"
          " valid enum via the make function" ) {
      THEN( "the Time has been converted to the correct unit" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] No Errors Expected";
        REQUIRE( Approx(1) ==
                 time_::make( 1.0 , time_::Unit::second ).value() );
        REQUIRE( Approx(1E-3) ==
                 time_::make( 1.0 , time_::Unit::millisecond ).value() );
        REQUIRE( Approx(1E-6) ==
                 time_::make( 1.0 , time_::Unit::microsecond ).value() );
        REQUIRE( Approx(1e-9) ==
                 time_::make( 1.0 , time_::Unit::nanosecond ).value() );
        REQUIRE( Approx(60) ==
                 time_::make( 1.0 , time_::Unit::minute ).value() );
        REQUIRE( Approx(3600) ==
                 time_::make( 1.0 , time_::Unit::hour ).value() );
        REQUIRE( Approx(86400) ==
                 time_::make( 1.0 , time_::Unit::day ).value() );
        REQUIRE( Approx(31556926.08) ==
                 time_::make( 1.0 , time_::Unit::year ).value() ); 
      }
    }

    WHEN( "constructing a time Value with an"
          " invalid enum via the make function" ) {
      THEN( "the Time has been converted to the correct unit" ) {
        LOG(INFO) << "Test " << ++testNumber << ": [make] Errors Expected";
        auto sillyUnit = static_cast< time_::Unit >( 1024 );
        REQUIRE_THROWS( time_::make( 1.0, sillyUnit ) );
      }
    }
  }
}
