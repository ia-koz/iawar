#include "ground.h++"


namespace ia
{
	ia::unit::ground_sptr ground::theground( void )
	{
		return ia::unit::ground_sptr( this );
	}
}