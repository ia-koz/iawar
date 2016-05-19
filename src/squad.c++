#include "squad.h++"


namespace ia
{
	ia::unit::squad_sptr squad::thesquad( void )
	{
		return ia::unit::squad_sptr( this );
	}
}
