#define CATCH_CONFIG_RUNNER

#include "catch.hpp"

#include "unit/time.hpp"

int testNumber = 0;

int main( int argc, const char* argv[] )
{
  LOG(INFO) << "";
  LOG(INFO) << " Time Tests";
  LOG(INFO) << "======================";
  int result = Catch::Session().run( argc, argv );
  LOG(INFO) << "Time Tests Complete!";
  return result;
}

namespace time_ = unit::time;

SCENARIO("Value constructor ", "[unit], [time], [Value], [ctor]") {

  LOG(INFO) << "Test " << ++testNumber << ": [construction] No Errors Expected";

  GIVEN("a physical time value"){

    WHEN("constructing a valid time quantity with the constructor") {

      THEN("the constructor should convert to the correct unit") {
        REQUIRE( Approx(1E-9) == time_::Value( 1.0 * time_::ns ).value() );
        REQUIRE( Approx(1E-6) == time_::Value( 1.0 * time_::us ).value() );
        REQUIRE( Approx(1E-3) == time_::Value( 1.0 * time_::ms ).value() );
        REQUIRE( Approx(1) == time_::Value( 1.0 * time_::s ).value() );
        REQUIRE( Approx(60) == time_::Value( 1.0 * time_::min ).value() );
        REQUIRE( Approx(3600) == time_::Value( 1.0 * time_::hour ).value() );
        REQUIRE( Approx(86400) == time_::Value( 1.0 * time_::d ).value() );
        REQUIRE( Approx(31556926.08) == time_::Value( 1.0 * time_::y ).value() );
      }
    }
  }
}
