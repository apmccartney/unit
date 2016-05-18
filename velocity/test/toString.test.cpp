#include "catch.hpp"

#include <tuple>
#include <string>
#include <vector>

#include "unit/velocity.hpp"

namespace velocity = unit::velocity;

extern int testNumber;
extern std::vector< std::pair< velocity::Unit, std::string > > units;

SCENARIO("toString function", "[unit], [velocity], [toString]") {
  GIVEN("a set of Unit enumerations and associated strings"){    
    WHEN("the enumeration component is passed to the toString function") {
      THEN("the result will match the associated string") {
        LOG(INFO) << "Test " << ++testNumber
                  << ": [toString] No Errors Expected";
        for ( auto& pair : units ){
          REQUIRE(pair.second == velocity::toString(pair.first) );
        }
      }
    }
  }
  GIVEN("an illegal Unit enumeration"){
    auto sillyUnit = static_cast<velocity::Unit>(1024);
    WHEN("the enumeration is passed to the toString function") {
      THEN("the function will throw"){
        LOG(INFO) << "Test " << ++testNumber
                  << ": [toString] Errors Expected";
        REQUIRE_THROWS( velocity::toString(sillyUnit) );
      }
    }
  }
}
