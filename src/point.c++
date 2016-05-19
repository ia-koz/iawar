#include <sstream>

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

	ia::point::coord_t point::x( void ) const
	{
		return point__x;
	}

	void point::x( const ia::point::coord_t & Value )
	{
		point__x = Value;
	}

	ia::point::coord_t point::y( void ) const
	{
		return point__y;
	}

	void point::y( const ia::point::coord_t & Value )
	{
		point__y = Value;
	}

	ia::point::coord_t point::z( void ) const
	{
		return point__z;
	}

	void point::z( const ia::point::coord_t & Value )
	{
		point__z = Value;
	}

	void point::ass( const ia::point & That )
	{
		if ( this != &That )
		{
			point__x = That.point__x;
			point__y = That.point__y;
			point__z = That.point__z;
		}
	}

	void point::add( const ia::point & That )
	{
		point__x += That.point__x;
		point__y += That.point__y;
		point__z += That.point__z;
	}

	void point::sub( const ia::point & That )
	{
		point__x -= That.point__x;
		point__y -= That.point__y;
		point__z -= That.point__z;
	}

	bool_t point::eqa( const ia::point & That ) const
	{
		return ( ( point__x == That.point__x ) && ( point__y == That.point__y ) && ( point__z == That.point__z ) );
	}

	string_t point::str( void ) const
	{
		std::stringstream ss;
		ss << "Point( " << point__x << " , " << point__y << " , " << point__z << " )";

		return ss.str( );
	}

	ia::point & point::operator =( const ia::point & That )
	{
		ass( That );

		return *this;
	}

	bool_t point::operator ==( const ia::point & That ) const
	{
		return eqa( That );
	}

	bool_t point::operator !=( const ia::point & That ) const
	{
		return !( eqa( That ) );
	}

	ia::point point::operator +( const ia::point & That ) const
	{
		ia::point tmp( *this );
		tmp.add( That );
		return tmp;
	}

	ia::point point::operator -( const ia::point & That ) const
	{
		ia::point tmp( *this );
		tmp.sub( That );
		return tmp;
	}

	ia::point & point::operator +=( const ia::point & That )
	{
		add( That );

		return *this;
	}

	ia::point & point::operator -=( const ia::point & That )
	{
		sub( That );

		return *this;
	}

	std::ostream & operator <<( std::ostream & Stream ,
								const ia::point & That )
	{
		Stream << That.str( );

		return Stream;
	}
}