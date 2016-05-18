#include <exception>
#include <unordered_map>

#include "unit/area.hpp"

using namespace unit::area;

/**
 * @param[in] string   the string to be converted
 *
 * @return The area unit value read from the string
 *
 * @throw std::invalid_argument   No conversion could be performed
 */
Unit
unit::area::toUnit( const std::string& label ) {
  
  const static std::unordered_map< std::string, Unit > 
    enumerationMap  = { { "m2",  Unit::squareMeter },
                        { "cm2", Unit::squareCentimeter },
                        { "mm2", Unit::squareMillimeter },
                        { "um2", Unit::squareMicrometer },
                        { "nm2", Unit::squareNanometer } };
  
  const auto entryIterator = enumerationMap.find( label );
  if ( entryIterator == enumerationMap.end() ){
    LOG(ERROR) << "Argument string does not correspond to a area unit";
    LOG(INFO) << "Argument string: " << label;
    LOG(INFO) << "Error in unit::area::toUnit function";
    throw std::invalid_argument
          ( "label argument does not correspond to a recognized area unit" );
  }
  return entryIterator->second;
}

