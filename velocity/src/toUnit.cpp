#include <exception>
#include <unordered_map>

#include "unit/velocity.hpp"

using namespace unit::velocity;

/**
 * @param[in] string   the string to be converted
 *
 * @return The velocity unit value read from the string
 *
 * @throw std::invalid_argument   No conversion could be performed
 */
Unit
unit::velocity::toUnit( const std::string& label ) {

#define MAP_ENTRY( unitLabel ) { symbol< Unit::unitLabel >, Unit::unitLabel }
  
  const static std::unordered_map< std::string, Unit > 
    enumerationMap  = { MAP_ENTRY( meterPerSecond ),
                        MAP_ENTRY( centimeterPerSecond ),
                        MAP_ENTRY( kilometerPerHour ) };

#undef MAP_ENTRY
  
  const auto entryIterator = enumerationMap.find( label );
  if ( entryIterator == enumerationMap.end() ){
    LOG(ERROR) << "Argument string does not correspond to a velocity unit";
    LOG(INFO) << "Argument string: " << label;
    LOG(INFO) << "Error in unit::velocity::toUnit function";
    throw std::invalid_argument
          ( "label argument does not correspond to a recognized velocity unit" );
  }
  return entryIterator->second;
}

