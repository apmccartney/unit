#include <exception>
#include <unordered_map>

#include "unit/velocity.hpp"

using namespace unit::velocity;

/**
 * @param[in] value   the velocity unit to be converted
 *
 * @return The velocity unit written to a string
 */
const std::string&
unit::velocity::toString( const Unit& unit ) {
  const static std::unordered_map< Unit, std::string > 
    stringMap  = { { Unit::meterPerSecond, "meter per second" },
                   { Unit::centimeterPerSecond, "centimeter per second" },
                   { Unit::kilometerPerHour, "kilometer per hour" } };
  
  const auto entryIterator = stringMap.find( unit );
  if ( entryIterator == stringMap.end() ){
    LOG(ERROR) << "Illegal unit argument encountered";
    LOG(INFO) << "Error in unit::velocity::toString function";
    throw std::domain_error("Illegal unit argument");
  }
  return entryIterator->second;
}

