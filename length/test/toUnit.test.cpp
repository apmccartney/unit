#include "catch.hpp"

#include <tuple>
#include <string>
#include <vector>

#include "unit/length.hpp"

extern int testNumber;

namespace length = unit::length;

SCENARIO("toUnit function", "[unit], [length], [toUnit]") {
  GIVEN("a set of Unit enumerations and associated strings"){
    std::vector< std::pair< length::Unit, std::string > >
      units = { { length::Unit::meter, "m" },
                { length::Unit::centimeter, "cm" },
                { length::Unit::millimeter, "mm" },
                { length::Unit::micrometer, "um" },
                { length::Unit::nanometer, "nm" } };
    WHEN("the string component is passed to the toUnit function") {
      THEN("the result will match the associated enumeration type") {
        LOG(INFO) << "Test " << ++testNumber
                  << ": [toUnit] No Errors Expected";
        for ( auto& pair : units ){
          REQUIRE(pair.first == length::toUnit(pair.second) );
        }
      }
    }
  }
  GIVEN("an illegal unit string"){
    auto sillyUnit = std::string("foo");
    WHEN("the unit string is passed to the toUnit function") {
      THEN("the function will throw"){
        LOG(INFO) << "Test " << ++testNumber
                  << ": [toUnit] Errors Expected";
        REQUIRE_THROWS( length::toUnit(sillyUnit) );
      }
    }
  }
}
