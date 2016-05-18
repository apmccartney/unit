#include <exception>

#include "unit/volume.hpp"

using namespace unit::volume;

/**
 * @param[in] magnitude   the volume value
 * @param[in] unit        the volume unit in which the value is given
 *
 * @return A volume::Value
 */
Value
unit::volume::make( const double magnitude, const Unit& unit) {
  switch (unit) {
  case Unit::cubicMeter :
    return Value( magnitude * m3 );
  case Unit::cubicCentimeter :
    return Value( magnitude * cm3 );
  case Unit::cubicMillimeter :
    return Value( magnitude * mm3 );
  case Unit::cubicMicrometer :
    return Value( magnitude * um3 );
  case Unit::cubicNanometer :
    return Value( magnitude * nm3 );
  default :
    LOG(ERROR) << "'unit' argument is not a valid Unit enumeration";
    LOG(INFO) << "Error in unit::volume::make function";
    throw std::domain_error("Illegal unit argument");
  }
}

/**
 * @param[in] magnitude   the volume value
 * @param[in] unit        the volume unit in which the value is given
 *
 * @return A volume::Value
 *
 * @throw std::invalid_argument   the string cannot be converted to a unit
 */
Value
unit::volume::make( const double value, const std::string& unit ) {
  return make( value, toUnit(unit) );
}
