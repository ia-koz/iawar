#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "defs.h++"
#include "unit.h++"


namespace ia
{
	class squad : public virtual ia::unit
	{
		public:
		virtual							~squad( void ) {};


		virtual ia::unit::squad_sptr	thesquad( void )								override;


		virtual void					add( ia::unit::unit_sptr & Slave )				= 0;		// Add slave unit.
	};
}


#endif // SQUAD_HPP
