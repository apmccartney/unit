#include <sstream>
#include <string>
#include <type_traits>

#include "catch.hpp"

#include "unit/length.hpp"

extern int testNumber;

using namespace unit;

SCENARIO("right shift operator", "[unit]") {
  Quantity< Centimeter > L1;        
  Quantity< Meter > L2;
  Quantity< Second > T1;        
  
  GIVEN("length values"){
    std::istringstream iss("50 cm 0.5 m 500 mm 5000 mm 10 s");
    WHEN("dumped from an istream") {
      THEN("the stream contents will match the reference") {
        LOG(INFO) << "Test " << ++testNumber
                  << ": [operator>>] No Errors Expected";
        iss >> L1;
        REQUIRE( Approx(50) == L1.value() );
        iss >> L2;
        REQUIRE( Approx(0.5) == L2.value() );
        iss >> L1;
        REQUIRE( Approx(50) == L1.value() );
        iss >> L2;
        REQUIRE( Approx(5.) == L2.value() );
        LOG(INFO) << "Test " << ++testNumber
                  << ": [operator>>] Errors Expected";
        REQUIRE_THROWS(iss >> L1);
        iss.clear();
        REQUIRE_THROWS(iss >> L2);
        iss.clear();
        LOG(INFO) << "Test " << ++testNumber
                  << ": [operator>>] No Errors Expected";
        iss >> T1;
        REQUIRE( Approx(10.) == T1.value() );
      }
    }
  }
}
