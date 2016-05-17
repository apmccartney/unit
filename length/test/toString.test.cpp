#include "catch.hpp"

#include <tuple>
#include <string>
#include <vector>

#include "unit/length.hpp"

extern int testNumber;

namespace length = unit::length;

SCENARIO("toString function", "[unit], [length], [toString]") {
  GIVEN("a set of Unit enumerations and associated strings"){
    std::vector< std::pair< length::Unit, std::string > >
      units = { { length::Unit::meter, "m" },
                { length::Unit::centimeter, "cm" },
                { length::Unit::millimeter, "mm" },
                { length::Unit::micrometer, "um" },
                { length::Unit::nanometer, "nm" } };
    WHEN("the enumeration component is passed to the toString function") {
      THEN("the result will match the associated string") {
        LOG(INFO) << "Test " << ++testNumber
                  << ": [toString] No Errors Expected";
        for ( auto& pair : units ){
          REQUIRE(pair.second == length::toString(pair.first) );
        }
      }
    }
  }
  GIVEN("an illegal Unit enumeration"){
    auto sillyUnit = static_cast<length::Unit>(1024);
    WHEN("the enumeration is passed to the toString function") {
      THEN("the function will throw"){
        LOG(INFO) << "Test " << ++testNumber
                  << ": [toString] Errors Expected";
        REQUIRE_THROWS( length::toString(sillyUnit) );
      }
    }
  }
}
