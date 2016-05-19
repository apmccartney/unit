#include "catch.hpp"

#include <tuple>
#include <string>
#include <vector>

#include "unit/area.hpp"

extern int testNumber;

namespace area = unit::area;

SCENARIO("toString function", "[unit], [area], [toString]") {
  GIVEN("a set of Unit enumerations and associated strings"){
    std::vector< std::pair< area::Unit, std::string > >
      units = { { area::Unit::squareMeter, "m2" },
                { area::Unit::squareCentimeter, "cm2" },
                { area::Unit::squareMillimeter, "mm2" },
                { area::Unit::squareMicrometer, "um2" },
                { area::Unit::squareNanometer, "nm2" } };
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
    auto sillyUnit = static_cast<area::Unit>(1024);
    WHEN("the enumeration is passed to the toString function") {
      THEN("the function will throw"){
        LOG(INFO) << "Test " << ++testNumber
                  << ": [toString] Errors Expected";
        REQUIRE_THROWS( unit::toString(sillyUnit) );
      }
    }
  }
}
