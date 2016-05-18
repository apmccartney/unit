#include "catch.hpp"

#include <tuple>
#include <string>
#include <vector>

#include "unit/area.hpp"

extern int testNumber;

namespace area = unit::area;

SCENARIO("toUnit function", "[unit], [area], [toUnit]") {
  GIVEN("a set of Unit enumerations and associated strings"){
    std::vector< std::pair< area::Unit, std::string > >
      units = { { area::Unit::squareMeter, "m2" },
                { area::Unit::squareCentimeter, "cm2" },
                { area::Unit::squareMillimeter, "mm2" },
                { area::Unit::squareMicrometer, "um2" },
                { area::Unit::squareNanometer, "nm2" } };
    WHEN("the string component is passed to the toUnit function") {
      THEN("the result will match the associated enumeration type") {
        LOG(INFO) << "Test " << ++testNumber
                  << ": [toUnit] No Errors Expected";
        for ( auto& pair : units ){
          REQUIRE(pair.first == area::toUnit(pair.second) );
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
        REQUIRE_THROWS( area::toUnit(sillyUnit) );
      }
    }
  }
}
