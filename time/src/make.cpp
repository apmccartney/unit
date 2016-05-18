#include <exception>

#include "unit/time.hpp"

using namespace unit::time;

/**
 * @param[in] magnitude   the time value
 * @param[in] unit        the time unit in which the value is given
 *
 * @return A time::Value
 */
Value
unit::time::make( const double magnitude, const Unit& unit) {
  switch (unit) {
  case Unit::second :
    return Value( magnitude * s );
  case Unit::nanosecond :
    return Value( magnitude * ns );
  case Unit::microsecond :
    return Value( magnitude * us );
  case Unit::millisecond :
    return Value( magnitude * ms );
  case Unit::minute :
    return Value( magnitude * min );
  case Unit::hour :
    return Value( magnitude * hour );
  case Unit::day :
    return Value( magnitude * d );
  case Unit::year :
    return Value( magnitude * y );
  default :
    LOG(ERROR) << "'unit' argument is not a valid Unit enumeration";
    LOG(INFO) << "Error in unit::time::make function";
    throw std::domain_error("Illegal unit argument");
  }
}

/**
 * @param[in] magnitude   the time value
 * @param[in] unit        the time unit in which the value is given
 *
 * @return A time::Value
 *
 * @throw std::invalid_argument   the string cannot be converted to a unit
 */
Value
unit::time::make( const double value, const std::string& unit ) {
  return make( value, toUnit(unit) );
}
