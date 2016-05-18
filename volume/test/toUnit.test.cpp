#include "catch.hpp"

#include <tuple>
#include <string>
#include <vector>

#include "unit/volume.hpp"

extern int testNumber;

namespace volume = unit::volume;

SCENARIO("toUnit function", "[unit], [volume], [toUnit]") {
  GIVEN("a set of Unit enumerations and associated strings"){
    std::vector< std::pair< volume::Unit, std::string > >
      units = { { volume::Unit::cubicMeter, "m3" },
                { volume::Unit::cubicCentimeter, "cm3" },
                { volume::Unit::cubicMillimeter, "mm3" },
                { volume::Unit::cubicMicrometer, "um3" },
                { volume::Unit::cubicNanometer, "nm3" } };
    WHEN("the string component is passed to the toUnit function") {
      THEN("the result will match the associated enumeration type") {
        LOG(INFO) << "Test " << ++testNumber
                  << ": [toUnit] No Errors Expected";
        for ( auto& pair : units ){
          REQUIRE(pair.first == volume::toUnit(pair.second) );
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
        REQUIRE_THROWS( volume::toUnit(sillyUnit) );
      }
    }
  }
}
