#include <exception>
#include <unordered_map>

#include "unit/length.hpp"

using namespace unit::length;

/**
 * @param[in] value   the length unit to be converted
 *
 * @return The length unit written to a string
 */
const std::string&
unit::length::toString( const Unit& unit ) {
  const static std::unordered_map< Unit, std::string > 
    stringMap  = { { Unit::meter, "m" },
                   { Unit::centimeter, "cm" },
                   { Unit::millimeter, "mm" },
                   { Unit::micrometer, "um" },
                   { Unit::nanometer, "nm" } };
  
  const auto entryIterator = stringMap.find( unit );
  if ( entryIterator == stringMap.end() ){
    LOG(ERROR) << "Illegal unit argument encountered";
    LOG(INFO) << "Error in unit::length::toString function";
    throw std::domain_error("Illegal unit argument");
  }
  return entryIterator->second;
}

