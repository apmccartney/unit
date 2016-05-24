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

using namespace unit;

SCENARIO("constructor ", "[unit], [time], [ctor]") {

  LOG(INFO) << "Test " << ++testNumber << ": [construction] No Errors Expected";

  GIVEN("a physical time value"){

    WHEN("constructing a valid time quantity with the constructor") {

      THEN("the constructor should convert to the correct unit") {
        REQUIRE( Approx(1E-9) == Quantity< Second >( 1.0 * time::ns ).value() );
        REQUIRE( Approx(1E-6) == Quantity< Second >( 1.0 * time::us ).value() );
        REQUIRE( Approx(1E-3) == Quantity< Second >( 1.0 * time::ms ).value() );
        REQUIRE( Approx(1) == Quantity< Second >( 1.0 * time::s ).value() );
        REQUIRE( Approx(60) == Quantity< Second >( 1.0 * time::min ).value() );
        REQUIRE( Approx(3600) == Quantity< Second >( 1.0 * time::hour ).value() );
        REQUIRE( Approx(86400) == Quantity< Second >( 1.0 * time::d ).value() );
        REQUIRE( Approx(31556926.08) == Quantity< Second >( 1.0 * time::y ).value() );
      }
    }
  }
}
