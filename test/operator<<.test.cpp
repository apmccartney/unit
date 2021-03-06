#include <sstream>
#include <string>
#include <type_traits>

#include "catch.hpp"

#include "unit/length.hpp"
// #include "unit/area.hpp"
// #include "unit/volume.hpp"
// #include "unit/time.hpp"
// #include "unit/velocity.hpp"

extern int testNumber;

using namespace unit;

SCENARIO("left shift operator", "[unit]") {
  Quantity< Centimeter >  L1( 0.5 * length::m );        
  Quantity< Meter > L2( 0.5 * m );

  // time_::Value T1( 1800 * time_::s );
  // unit::Quantity< time_::Hour > T2( 0.5 * time_::hour );

  // std::string reference("50 cm == 0.5 m\n1800 s == 0.5 hour");
  std::string reference("50 cm == 0.5 m");
  GIVEN("length and time values"){
    std::ostringstream oss;
    WHEN("dumped to an ostream") {
      THEN("the stream contents will match the reference") {
        LOG(INFO) << "Test " << ++testNumber
                  << ": [operator<<] No Errors Expected";
        oss << L1 << " == " << L2;// << '\n' << T1 << " == " << T2;
        REQUIRE( reference == oss.str() );
      }
    }
  }
}
