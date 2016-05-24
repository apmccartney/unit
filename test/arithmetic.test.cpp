// #include <type_traits>

// #include "catch.hpp"

// #include "unit/length.hpp"
// #include "unit/area.hpp"
// #include "unit/volume.hpp"
// #include "unit/time.hpp"
// #include "unit/velocity.hpp"

// extern int testNumber;

// namespace length = unit::length;
// namespace area = unit::area;
// namespace volume = unit::volume;
// namespace time_ = unit::time;
// namespace velocity = unit::velocity;

// SCENARIO("arithmetic operators", "[unit]") {
//   length::Value L1( 0.5 * length::cm );
//   time_::Value T1( 2.0 * time_::s );
//   GIVEN("a length value"){
//     WHEN("using the multiplication operator") {
//       THEN("return values are in area and volume units") {
//         {
//           LOG(INFO) << "Test " << ++testNumber
//                     << ": [arithmetic] No Errors Expected";
//           area::Value A0 = L1 * L1 * L1 / L1;
//           area::Value A1 = L1 * L1;
//           REQUIRE( Approx(0.25) == A0.value() );
//           REQUIRE( Approx(0.25) == A1.value() );

//           auto isDefaultAreaType =
//             std::is_same< decltype(A1),
//                           unit::Quantity< area::SquareCentimeter > >::value;
//           REQUIRE( isDefaultAreaType );

//           /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
//           /* why we don't use auto with the unit library types */
//           /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
//           auto A2 = L1 * L1;
//           REQUIRE( Approx(0.25) == A2.value() ); // looks like square centimeter
//           auto isWeirdType =
//             not std::is_same< decltype(A1), decltype(A2) >::value;

//           REQUIRE( isWeirdType ); // but isn't square centimeter type
//         }

//         {
//           LOG(INFO) << "Test " << ++testNumber
//                     << ": [arithmetic] No Errors Expected";
          
//           volume::Value V0 = L1 * L1 * L1;
//           area::Value A0 = L1 * L1;
//           volume::Value V1 = A0 * L1;
//           REQUIRE( Approx(0.125) == V1.value() );
//           REQUIRE( Approx(0.125) == V1.value() );
//         }
        
//       }
//     }
//   }
// }
