#include <exception>
#include <unordered_map>

#include "unit/length.hpp"

using namespace unit::length;

/**
 * @param[in] string   the string to be converted
 *
 * @return The length unit value read from the string
 *
 * @throw std::invalid_argument   No conversion could be performed
 */
Unit
unit::length::toUnit( const std::string& label ) {
  const static std::unordered_map< std::string, Unit > 
    enumerationMap  = { { "m",  Unit::meter },
                        { "cm", Unit::centimeter },
                        { "mm", Unit::millimeter },
                        { "um", Unit::micrometer },
                        { "nm", Unit::nanometer } };
  
  const auto entryIterator = enumerationMap.find( label );
  if ( entryIterator == enumerationMap.end() ){
    LOG(ERROR) << "Argument string does not correspond to a length unit";
    LOG(INFO) << "Argument string: " << label;
    LOG(INFO) << "Error in unit::length::toUnit function";
    throw std::invalid_argument
          ( "label argument does not correspond to a recognized length unit" );
  }
  return entryIterator->second;
}

