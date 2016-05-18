#include <type_traits>

#include "catch.hpp"

#include "unit/velocity.hpp"

extern int testNumber;

namespace velocity = unit::velocity;

SCENARIO("arithmetic operators", "[unit], [velocity]") {
  GIVEN("two velocity values"){
    WHEN("using the addition and subtraction operators") {
      THEN("the values and units given are correct") {
        velocity::Value L1( 1.0 * velocity::m_per_s );
        velocity::Value L2( 1E-3 * velocity::m_per_s );
        {
          LOG(INFO) << "Test " << ++testNumber
                    << ": [operator+] No Errors Expected";
          const auto L3 = L1 + L2;
          REQUIRE( Approx(1.001) == L3.value() );
        }
        {
          LOG(INFO) << "Test " << ++testNumber
                    << ": [Scalar operator*] No Errors Expected";
          auto L3 = 3.0 * L1;
          REQUIRE( Approx(3.0) == L3.value() );
        }
        {
          LOG(INFO) << "Test " << ++testNumber
                    << ": [operator-] No Errors Expected";
          auto L3 = L1 - L2;
          REQUIRE( Approx(0.999) == L3.value() );
        }
        {
          LOG(INFO) << "Test " << ++testNumber
                    << ": [arithmetic] No Errors Expected";
          auto L3 = 3.0 * L1 - 2.0 * L2;
          REQUIRE( Approx(2.998) == L3.value() );
          
          LOG(INFO) << "Test " << ++testNumber
                    << ": [arithmetic] No Errors Expected";
          L3 += 2.0 * L2;
          REQUIRE( Approx(3) == L3.value() );

          LOG(INFO) << "Test " << ++testNumber
                    << ": [arithmetic] No Errors Expected";
          L3 -= 3.0 * L1;
          REQUIRE( Approx(0) == L3.value() );
        }
      }
    }
  }
}
