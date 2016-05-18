#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "defs.h++"


namespace ia
{
	class point
	{
		public:
		typedef int_t			coord_t;

								point( void );														// Default constructor.
		explicit				point( const ia::point::coord_t & X ,
									   const ia::point::coord_t & Y ,
									   const ia::point::coord_t & Z );								// Param constructor.

								point( const point & That );										// Copy constructor.

		virtual					~point( void );														// Virtual destructor.


		ia::point::coord_t		x( void ) const;													// Return X-coordinate.
		void					x( const ia::point::coord_t & Value );								// Set X-coordinate.

		ia::point::coord_t		y( void ) const;													// Return Y-coordinate.
		void					y( const ia::point::coord_t & Value );								// Set Y-coordinate.

		ia::point::coord_t		z( void ) const;													// Return Z-coordinate.
		void					z( const ia::point::coord_t & Value );								// Set Z-coordinate.


		void					ass( const ia::point & That );										// Assignment That to *this.
		void					add( const ia::point & That );										// Addition That to *this.
		void					sub( const ia::point & That );										// Subtraction That to *this.

		bool_t					eqa( const ia::point & That ) const;								// Equality That to *this.

		string_t				str( void ) const;													// Return string representation.


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
