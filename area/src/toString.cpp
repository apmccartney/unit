#include <exception>
#include <unordered_map>

#include "unit/area.hpp"

using namespace unit::area;

/**
 * @param[in] value   the area unit to be converted
 *
 * @return The area unit written to a string
 */
const std::string&
unit::area::toString( const Unit& unit ) {
  const static std::unordered_map< Unit, std::string > 
    stringMap  = { { Unit::squareMeter, "m2" },
                   { Unit::squareCentimeter, "cm2" },
                   { Unit::squareMillimeter, "mm2" },
                   { Unit::squareMicrometer, "um2" },
                   { Unit::squareNanometer, "nm2" } };
  
  const auto entryIterator = stringMap.find( unit );
  if ( entryIterator == stringMap.end() ){
    LOG(ERROR) << "Illegal unit argument encountered";
    LOG(INFO) << "Error in unit::area::toString function";
    throw std::domain_error("Illegal unit argument");
  }
  return entryIterator->second;
}

