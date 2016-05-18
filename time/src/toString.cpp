#include <exception>
#include <unordered_map>

#include "unit/time.hpp"

using namespace unit::time;

/**
 * @param[in] value   the time unit to be converted
 *
 * @return The time unit written to a string
 */
const std::string&
unit::time::toString( const Unit& unit ) {

  const static std::unordered_map< Unit, std::string> 
    stringMap  = { { Unit::nanosecond , "ns"   },
                   { Unit::microsecond, "us"   },
                   { Unit::millisecond, "ms"   },
                   { Unit::second     , "s"    },
                   { Unit::minute     , "min"  },
                   { Unit::hour       , "hour" },
                   { Unit::day        , "d"    },
                   { Unit::year       , "y"    } };
  
  const auto entryIterator = stringMap.find( unit );
  if ( entryIterator == stringMap.end() ){
    LOG(ERROR) << "Illegal unit argument encountered";
    LOG(INFO) << "Error in unit::time::toString function";
    throw std::domain_error("Illegal unit argument");
  }
  return entryIterator->second;
}

