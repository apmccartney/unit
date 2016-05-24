#include <type_traits>

#include "catch.hpp"

#include "unit/length.hpp"
#include "unit/area.hpp"
#include "unit/volume.hpp"
#include "unit/time.hpp"
#include "unit/velocity.hpp"

extern int testNumber;

using namespace unit;

SCENARIO("arithmetic operators", "[unit]") {
  Quantity< Centimeter > L1( 0.5 * cm );
  Quantity< Second > T1( 2.0 * s );
  GIVEN("a length value"){
    WHEN("using the multiplication operator") {
      THEN("return values are in area and volume units") {
        {
          LOG(INFO) << "Test " << ++testNumber
                    << ": [arithmetic] No Errors Expected";
          Quantity< SquareCentimeter > A0 = L1 * L1 * L1 / L1;
          Quantity< SquareCentimeter > A1 = L1 * L1;
          REQUIRE( Approx(0.25) == A0.value() );
          REQUIRE( Approx(0.25) == A1.value() );

          auto isDefaultAreaType =
            std::is_same< decltype(A1),
                          Quantity<SquareCentimeter > >::value;
          REQUIRE( isDefaultAreaType );

          /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          /* why we don't use auto with the unit library types */
          /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          auto A2 = L1 * L1;
          REQUIRE( Approx(0.25) == A2.value() ); // looks like square centimeter
          auto isWeirdType =
            not std::is_same< decltype(A1), decltype(A2) >::value;

          REQUIRE( isWeirdType ); // but isn't square centimeter type
        }

        {
          LOG(INFO) << "Test " << ++testNumber
                    << ": [arithmetic] No Errors Expected";
          
          Quantity< CubicCentimeter > V0 = L1 * L1 * L1;
          Quantity< SquareCentimeter > A0 = L1 * L1;
          Quantity< CubicCentimeter > V1 = A0 * L1;
          REQUIRE( Approx(0.125) == V1.value() );
          REQUIRE( Approx(0.125) == V1.value() );
        }
        
      }
    }
  }
}
