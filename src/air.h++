#ifndef AIR_HPP
#define AIR_HPP

#include "defs.h++"
#include "unit.h++"


namespace ia
{
	class air : public virtual ia::unit
	{
		public:
		virtual							~air( void ) {};


		virtual ia::unit::air_sptr		theair( void )									override;


		virtual void					up( void )										= 0;		// Go one step up.
		virtual void					down( void )									= 0;		// Go one step down.
	};
}


#endif // AIR_HPP
