#include "catch.hpp"

#include <tuple>
#include <string>
#include <vector>

#include "unit/time.hpp"

extern int testNumber;

namespace time_ = unit::time;

SCENARIO("toUnit function", "[unit], [time], [toUnit]") {
  GIVEN("a set of Unit enumerations and associated strings"){
    std::vector< std::pair< time_::Unit, std::string > >
      units = { { time_::Unit::nanosecond , "ns"   },
                { time_::Unit::microsecond, "us"   },
                { time_::Unit::millisecond, "ms"   },
                { time_::Unit::second     , "s"    },
                { time_::Unit::minute     , "min"  },
                { time_::Unit::hour       , "hour" },
                { time_::Unit::day        , "d"    },
                { time_::Unit::year       , "y"    } };

    WHEN("the string component is passed to the toUnit function") {
      THEN("the result will match the associated enumeration type") {
        LOG(INFO) << "Test " << ++testNumber
                  << ": [toUnit] No Errors Expected";
        for ( auto& pair : units ){
          REQUIRE(pair.first == time_::toUnit(pair.second) );
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
        REQUIRE_THROWS( time_::toUnit(sillyUnit) );
      }
    }
  }
}
