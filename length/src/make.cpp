#include <exception>

#include "unit/length.hpp"

using namespace unit::length;

/**
 * @param[in] magnitude   the length value
 * @param[in] unit        the length unit in which the value is given
 *
 * @return A length::Value
 */
Value
unit::length::make( const double magnitude, const Unit& unit) {
  switch (unit) {
  case Unit::meter :
    return Value( magnitude * m );
  case Unit::centimeter :
    return Value( magnitude * cm );
  case Unit::millimeter :
    return Value( magnitude * mm );
  case Unit::micrometer :
    return Value( magnitude * um );
  case Unit::nanometer :
    return Value( magnitude * nm );
  default :
    LOG(ERROR) << "'unit' argument is not a valid Unit enumeration";
    LOG(INFO) << "Error in unit::length::make function";
    throw std::domain_error("Illegal unit argument");
  }
}

/**
 * @param[in] magnitude   the length value
 * @param[in] unit        the length unit in which the value is given
 *
 * @return A length::Value
 *
 * @throw std::invalid_argument   the string cannot be converted to a unit
 */
// Value
// unit::length::make( const double value, const std::string& unit ) {
//   return make( value, toUnit(unit) );
// }
