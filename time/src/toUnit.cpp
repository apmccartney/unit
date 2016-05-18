#include <exception>
#include <unordered_map>

#include "unit/time.hpp"

using namespace unit::time;

/**
 * @param[in] string   the string to be converted
 *
 * @return The time unit value read from the string
 *
 * @throw std::invalid_argument   No conversion could be performed
 */
Unit
unit::time::toUnit( const std::string& label ) {
  
  const static std::unordered_map< std::string, Unit > 
    enumerationMap  = { { "ns",  Unit::nanosecond },
                        { "us",  Unit::microsecond },
                        { "ms",  Unit::millisecond },
                        { "s",  Unit::second },
                        { "min", Unit::minute },
                        { "hour", Unit::hour },
                        { "d", Unit::day },
                        { "y", Unit::year } };
  
  const auto entryIterator = enumerationMap.find( label );
  if ( entryIterator == enumerationMap.end() ){
    LOG(ERROR) << "Argument string does not correspond to a time unit";
    LOG(INFO) << "Argument string: " << label;
    LOG(INFO) << "Error in unit::time::toUnit function";
    throw std::invalid_argument
          ( "label argument does not correspond to a recognized time unit" );
  }
  return entryIterator->second;
}
