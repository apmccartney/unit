#define CATCH_CONFIG_RUNNER

#include "catch.hpp"

#include "unit/velocity.hpp"

int testNumber = 0;

using namespace unit;

int main( int argc, const char* argv[] )
{
  LOG(INFO) << "";
  LOG(INFO) << " Velocity Tests";
  LOG(INFO) << "======================";
  int result = Catch::Session().run( argc, argv );
  LOG(INFO) << "Velocity Tests Complete!";
  return result;
}

SCENARIO("constructor ", "[unit], [velocity], [ctor]") {

   LOG(INFO) << "Test " << ++testNumber << ": [construction] No Errors Expected";

   GIVEN("a physical velocity value"){

     WHEN("constructing a valid Velocity with the constructor") {

       THEN("the constructor should convert to the correct unit") {

         REQUIRE( Approx(.01) ==
                  Quantity< MeterPerSecond >( 1.0 * velocity::cm_per_s ).value() );
         REQUIRE( Approx(1) ==
                  Quantity< MeterPerSecond >( 1.0 * velocity::m_per_s ).value() );
         REQUIRE( Approx(0.27777777777) ==
                  Quantity< MeterPerSecond >( 1.0 * velocity::km_per_hour ).value() );

       }
     }
   }
}
