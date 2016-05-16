#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "defs.h++"


namespace ia
{
	class point
	{
		public:
		typedef int_t					coord_t;

								point( void );														// Default constructor.
		explicit				point( const ia::point::coord_t & X ,
									   const ia::point::coord_t & Y ,
									   const ia::point::coord_t & Z );								// Param constructor.

								point( const point & That );										// Copy constructor.

		virtual					~point( void );														// Virtual destructor.

		ia::point &				operator =( const ia::point & That );								// Assignment operator.


		bool_t					operator ==( const ia::point & That ) const;						// Equality operator.
		bool_t					operator !=( const ia::point & That ) const;						// Inequality operator.

		
		ia::point				operator +( const ia::point & That ) const;							// Addition operator.
		ia::point				operator -( const ia::point & That ) const;							// Subtraction operator.
		ia::point &				operator +=( const ia::point & That );								// Addition assignment operator.
		ia::point &				operator -=( const ia::point & That );								// Subtraction assignment operator.


		friend std::ostream &	operator <<( std::ostream &		Stream ,
											 const ia::point &	That );


		private:
		coord_t					point__x;
		coord_t					point__y;
		coord_t					point__z;
	};
}


#endif //POINT_HPP
