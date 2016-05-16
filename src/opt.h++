#ifndef OPTION_HPP
#define OPTION_HPP

#include <getopt.h>
#include <vector>
#include <iostream>

#include "defs.h++"


namespace ia
{
	typedef std::vector<string_t>		optvalues;

	class opt
	{
		public:

		enum class requires : byte_t
		{
			none		= byte_t( no_argument ) ,
			require		= byte_t( required_argument ) ,
			optional	= byte_t( optional_argument )
		};

		enum class types : byte_t
		{
			unknown		= byte_t( 0x00 ) ,
			app			= byte_t( 0x01 ) ,
			arg			= byte_t( 0x02 ) ,
			opt			= byte_t( 0x04 ) ,
			flag		= byte_t( 0x08 ) ,
			nil			= byte_t( 0x10 ) ,
		};


		public:

		opt( void );

		opt( const char_t &				little ,
			 const string_t &			big ,
			 const ia::opt::requires &	require ,
			 const ia::opt::types &		type );

		virtual ~opt( void );


		char_t							little( void ) const;
		void							little( const char_t & value );

		string_t						big( void ) const;
		void							big( const string_t & value );

		ia::opt::requires				require( void ) const;
		void							require( const ia::opt::requires & value );

		ia::opt::types					type( void ) const;
		void							type( const ia::opt::types & value );

		::option						getgnuopt( void ) const;

		void							addoptvalue( const string_t & value );


		string_t						str( void ) const;

		friend std::ostream &			operator <<( std::ostream &			stream ,
													 const ia::opt &		opt );


		private:

		char_t							opt__little;
		string_t						opt__big;
		ia::opt::requires				opt__require;
		ia::opt::types					opt__type;
		ia::optvalues					opt__values;
	};
}

inline constexpr ia::opt::types operator&( ia::opt::types left , ia::opt::types right )
{
	return static_cast<ia::opt::types>( static_cast<byte_t>( left ) & static_cast<byte_t>( right ) );
}

inline constexpr ia::opt::types operator|( ia::opt::types left , ia::opt::types right )
{
	return static_cast<ia::opt::types>( static_cast<byte_t>( left ) | static_cast<byte_t>( right ) );
}

inline constexpr ia::opt::types operator^( ia::opt::types left , ia::opt::types right )
{
	return static_cast<ia::opt::types>( static_cast<byte_t>( left ) ^ static_cast<byte_t>( right ) );
}

inline constexpr ia::opt::types operator~( ia::opt::types left )
{
	return static_cast<ia::opt::types>( ~static_cast<byte_t>( left ) );
}

inline ia::opt::types & operator&=( ia::opt::types & left , ia::opt::types right )
{
	left = left & right;
	return left;
}

inline ia::opt::types & operator|=( ia::opt::types & left , ia::opt::types right )
{
	left = left | right;
	return left;
}

inline ia::opt::types & operator^=( ia::opt::types & left , ia::opt::types right )
{
	left = left ^ right;
	return left;
}


#endif // OPTION_HPP