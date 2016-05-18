#include <exception>
#include <unordered_map>

#include "unit/volume.hpp"

using namespace unit::volume;

/**
 * @param[in] string   the string to be converted
 *
 * @return The volume unit value read from the string
 *
 * @throw std::invalid_argument   No conversion could be performed
 */
Unit
unit::volume::toUnit( const std::string& label ) {
  
  const static std::unordered_map< std::string, Unit > 
    enumerationMap  = { { "m3",  Unit::cubicMeter },
                        { "cm3", Unit::cubicCentimeter },
                        { "mm3", Unit::cubicMillimeter },
                        { "um3", Unit::cubicMicrometer },
                        { "nm3", Unit::cubicNanometer } };
  
  const auto entryIterator = enumerationMap.find( label );
  if ( entryIterator == enumerationMap.end() ){
    LOG(ERROR) << "Argument string does not correspond to a volume unit";
    LOG(INFO) << "Argument string: " << label;
    LOG(INFO) << "Error in unit::volume::toUnit function";
    throw std::invalid_argument
          ( "label argument does not correspond to a recognized volume unit" );
  }
  return entryIterator->second;
}

