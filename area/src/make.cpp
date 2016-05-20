#include <exception>

#include "unit/area.hpp"

using namespace unit::area;

/**
 * @param[in] magnitude   the area value
 * @param[in] unit        the area unit in which the value is given
 *
 * @return A area::Value
 */
Value
unit::area::make( const double magnitude, const Unit& unit) {
  switch (unit) {
  case Unit::squareMeter :
    return Value( magnitude * m2 );
  case Unit::squareCentimeter :
    return Value( magnitude * cm2 );
  case Unit::squareMillimeter :
    return Value( magnitude * mm2 );
  case Unit::squareMicrometer :
    return Value( magnitude * um2 );
  case Unit::squareNanometer :
    return Value( magnitude * nm2 );
  default :
    LOG(ERROR) << "'unit' argument is not a valid Unit enumeration";
    LOG(INFO) << "Error in unit::area::make function";
    throw std::domain_error("Illegal unit argument");
  }
}

/**
 * @param[in] magnitude   the area value
 * @param[in] unit        the area unit in which the value is given
 *
 * @return A area::Value
 *
 * @throw std::invalid_argument   the string cannot be converted to a unit
 */
// Value
// unit::area::make( const double value, const std::string& unit ) {
//   return make( value, toUnit(unit) );
// }
