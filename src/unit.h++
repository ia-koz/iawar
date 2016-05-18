#ifndef UNIT_HPP
#define UNIT_HPP

#include <memory>

#include "defs.h++"
#include "point.h++"


namespace ia
{
	class ground;
	class air;
	class squad;

	class unit
	{
		public:
		typedef std::shared_ptr<ia::unit>	unit_sptr;
		typedef std::shared_ptr<ia::ground>	ground_sptr;
		typedef std::shared_ptr<ia::air>	air_sptr;
		typedef std::shared_ptr<ia::squad>	squad_sptr;


		virtual string_t				name( void ) const								= 0;		// Return name string representation.
		virtual string_t				type( void ) const								= 0;		// Return type string representation.

		virtual string_t				str( void ) const								= 0;		// Return string representation.


		virtual ia::unit::ground_sptr	theground( void );
		virtual ia::unit::air_sptr		theair( void );
		virtual ia::unit::squad_sptr	thesquad( void );
	};
}


#endif //UNIT_HPP
