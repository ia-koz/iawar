#include "point.h++"


namespace ia
{
	point::point( void )
		:
		point__x( ia::point::coord_t( 0 ) ) ,
		point__y( ia::point::coord_t( 0 ) ) ,
		point__z( ia::point::coord_t( 0 ) )
	{ }

	point::point( const ia::point::coord_t & X ,
				  const ia::point::coord_t & Y ,
				  const ia::point::coord_t & Z )
		:
		point__x( ia::point::coord_t( X ) ) ,
		point__y( ia::point::coord_t( Y ) ) ,
		point__z( ia::point::coord_t( Z ) )
	{ }

	point::point( const point & That )
		:
		point__x( ia::point::coord_t( That.point__x ) ) ,
		point__y( ia::point::coord_t( That.point__y ) ) ,
		point__z( ia::point::coord_t( That.point__z ) )
	{ }

	point::~point( void )
	{ }

	ia::point & point::operator =( const ia::point & That )
	{
		if ( this != &That )
		{
			point__x = That.point__x;
			point__y = That.point__y;
			point__z = That.point__z;
		}

		return *this;
	}

	bool_t point::operator ==( const ia::point & That ) const
	{
		return ( ( point__x == That.point__x ) && ( point__y == That.point__y ) && ( point__z == That.point__z ) );
	}

	bool_t point::operator !=( const ia::point & That ) const
	{
		return !( ( *this ) == That );
	}

	ia::point point::operator +( const ia::point & That ) const
	{
		return point( point__x + That.point__x , point__y + That.point__y , point__z + That.point__z );
	}

	ia::point point::operator -( const ia::point & That ) const
	{
		return point( point__x - That.point__x , point__y - That.point__y , point__z - That.point__z );
	}

	ia::point & point::operator +=( const ia::point & That )
	{
		point__x += That.point__x;
		point__y += That.point__y;
		point__z += That.point__z;

		return *this;
	}

	ia::point & point::operator -=( const ia::point & That )
	{
		point__x -= That.point__x;
		point__y -= That.point__y;
		point__z -= That.point__z;

		return *this;
	}

	std::ostream & operator <<( std::ostream & Stream ,
								const ia::point & That )
	{
		Stream << "Point( " << That.point__x << " , " << That.point__y << " , " << That.point__z << " )";

		return Stream;
	}
}