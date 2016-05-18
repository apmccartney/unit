#include "catch.hpp"

#include <tuple>
#include <string>
#include <vector>

#include "unit/velocity.hpp"

extern int testNumber;

namespace velocity = unit::velocity;

SCENARIO("toUnit function", "[unit], [velocity], [toUnit]") {
  GIVEN("a set of Unit enumerations and associated strings"){
    std::vector< std::pair< velocity::Unit, std::string > >
      units = { { velocity::Unit::meterPerSecond, "meter per second" },
                { velocity::Unit::centimeterPerSecond, "centimeter per second" },
                { velocity::Unit::kilometerPerHour, "kilometer per hour" } };

    WHEN("the string component is passed to the toUnit function") {
      THEN("the result will match the associated enumeration type") {
        LOG(INFO) << "Test " << ++testNumber
                  << ": [toUnit] No Errors Expected";
        for ( auto& pair : units ){
          REQUIRE(pair.first == velocity::toUnit(pair.second) );
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
        REQUIRE_THROWS( velocity::toUnit(sillyUnit) );
      }
    }
  }
}