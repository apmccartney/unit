#include "catch.hpp"

#include <tuple>
#include <string>
#include <vector>

#include "unit/volume.hpp"

extern int testNumber;

namespace volume = unit::volume;

SCENARIO("toString function", "[unit], [volume], [toString]") {
  GIVEN("a set of Unit enumerations and associated strings"){
    std::vector< std::pair< volume::Unit, std::string > >
      units = { { volume::Unit::cubicMeter, "m3" },
                { volume::Unit::cubicCentimeter, "cm3" },
                { volume::Unit::cubicMillimeter, "mm3" },
                { volume::Unit::cubicMicrometer, "um3" },
                { volume::Unit::cubicNanometer, "nm3" } };
    WHEN("the enumeration component is passed to the toString function") {
      THEN("the result will match the associated string") {
        LOG(INFO) << "Test " << ++testNumber
                  << ": [toString] No Errors Expected";
        for ( auto& pair : units ){
          REQUIRE(pair.second == unit::toString(pair.first) );
        }
      }
    }
  }
  GIVEN("an illegal Unit enumeration"){
    auto sillyUnit = static_cast<volume::Unit>(1024);
    WHEN("the enumeration is passed to the toString function") {
      THEN("the function will throw"){
        LOG(INFO) << "Test " << ++testNumber
                  << ": [toString] Errors Expected";
        REQUIRE_THROWS( unit::toString(sillyUnit) );
      }
    }
  }
}
