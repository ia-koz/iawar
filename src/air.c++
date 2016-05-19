#include "air.h++"


namespace ia
{
	ia::unit::air_sptr air::theair( void )
	{
		return ia::unit::air_sptr( this );
	}
}
