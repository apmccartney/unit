#include <exception>
#include <unordered_map>

#include "unit/volume.hpp"

using namespace unit::volume;

/**
 * @param[in] value   the volume unit to be converted
 *
 * @return The volume unit written to a string
 */
const std::string&
unit::volume::toString( const Unit& unit ) {
  const static std::unordered_map< Unit, std::string > 
    stringMap  = { { Unit::cubicMeter, "m3" },
                   { Unit::cubicCentimeter, "cm3" },
                   { Unit::cubicMillimeter, "mm3" },
                   { Unit::cubicMicrometer, "um3" },
                   { Unit::cubicNanometer, "nm3" } };
  
  const auto entryIterator = stringMap.find( unit );
  if ( entryIterator == stringMap.end() ){
    LOG(ERROR) << "Illegal unit argument encountered";
    LOG(INFO) << "Error in unit::volume::toString function";
    throw std::domain_error("Illegal unit argument");
  }
  return entryIterator->second;
}

