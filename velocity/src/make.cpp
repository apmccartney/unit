#include <exception>

#include "unit/velocity.hpp"

using namespace unit::velocity;

/**
 * @param[in] magnitude   the velocity value
 * @param[in] unit        the velocity unit in which the value is given
 *
 * @return A velocity::Value
 */
Value
unit::velocity::make( const double magnitude, const Unit& unit) {
  switch (unit) {
  case Unit::meterPerSecond :
    return Value( magnitude * m_per_s );
  case Unit::centimeterPerSecond :
    return Value( magnitude * cm_per_s );
  case Unit::kilometerPerHour :
    return Value( magnitude * km_per_hour );
  default :
    LOG(ERROR) << "'unit' argument is not a valid Unit enumeration";
    LOG(INFO) << "Error in unit::velocity::make function";
    throw std::domain_error("Illegal unit argument");
  }
}

/**
 * @param[in] magnitude   the velocity value
 * @param[in] unit        the velocity unit in which the value is given
 *
 * @return A velocity::Value
 *
 * @throw std::invalid_argument   the string cannot be converted to a unit
 */
Value
unit::velocity::make( const double value, const std::string& unit ) {
  return make( value, toUnit(unit) );
}
