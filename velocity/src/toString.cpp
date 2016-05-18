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
  
#define MAP_ENTRY( unitLabel ) { Unit::unitLabel, symbol< Unit::unitLabel > }
  
  const static std::unordered_map< Unit, std::string > 
    stringMap  = { MAP_ENTRY( meterPerSecond ),
                   MAP_ENTRY( centimeterPerSecond ),
                   MAP_ENTRY( kilometerPerHour ) };
                   
#undef MAP_ENTRY
                   
  const auto entryIterator = stringMap.find( unit );
  if ( entryIterator == stringMap.end() ){
    LOG(ERROR) << "Illegal unit argument encountered";
    LOG(INFO) << "Error in unit::velocity::toString function";
    throw std::domain_error("Illegal unit argument");
  }
  return entryIterator->second;
}

