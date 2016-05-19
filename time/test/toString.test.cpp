#include "catch.hpp"

#include <tuple>
#include <string>
#include <vector>

#include "unit/time.hpp"

extern int testNumber;

namespace time_ = unit::time;

SCENARIO("toString function", "[unit], [time], [toString]") {
  GIVEN("a set of Unit enumerations and associated strings"){
    std::vector< std::pair< time_::Unit, std::string > >
      units =  { { time_::Unit::nanosecond , "ns"   },
                 { time_::Unit::microsecond, "us"   },
                 { time_::Unit::millisecond, "ms"   },
                 { time_::Unit::second     , "s"    },
                 { time_::Unit::minute     , "min"  },
                 { time_::Unit::hour       , "hour" },
                 { time_::Unit::day        , "d"    },
                 { time_::Unit::year       , "y"    } };

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
    auto sillyUnit = static_cast<time_::Unit>(1024);
    WHEN("the enumeration is passed to the toString function") {
      THEN("the function will throw"){
        LOG(INFO) << "Test " << ++testNumber
                  << ": [toString] Errors Expected";
        REQUIRE_THROWS( unit::toString(sillyUnit) );
      }
    }
  }
}
