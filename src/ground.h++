#ifndef GROUND_HPP
#define GROUND_HPP

#include "defs.h++"
#include "unit.h++"


namespace ia
{
	class ground : public virtual ia::unit
	{
		public:
		virtual							~ground( void ) {};


		virtual void					forward( void )									= 0;		// Go one step forward.
		virtual void					back( void )									= 0;		// Go one step back.
		virtual void					left( void )									= 0;		// Go one step left.
		virtual void					right( void )									= 0;		// Go one step right.
	};
}


#endif // GROUND_HPP
