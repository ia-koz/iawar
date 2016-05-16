#ifndef UNIT_HPP
#define UNIT_HPP

#include "defs.h++"


namespace ia
{
	class unit
	{
		public:
			virtual void				x( const int_t Value ) = 0;
			virtual int_t				x( void ) const = 0;
	};
}


#endif //UNIT_HPP
