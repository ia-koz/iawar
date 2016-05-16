#include "opt.h++"


namespace ia
{
	opt::opt( void )
			:
			opt__little( 0 ) ,
			opt__big( string_t( ) ) ,
			opt__require( ia::opt::requires::none ) ,
			opt__type( ia::opt::types::unknown ) ,
			opt__values( )
	{ }

	opt::opt( const char_t & little ,
			  const string_t & big ,
			  const ia::opt::requires & require ,
			  const ia::opt::types & type )
			:
			opt__little( little ) ,
			opt__big( big ) ,
			opt__require( require ) ,
			opt__type( type ) ,
			opt__values( )
	{ }

	opt::~opt( void )
	{ }

	char_t opt::little( void ) const
	{
		return opt__little;
	}

	void opt::little( const char_t & value )
	{
		opt__little = value;
	}

	string_t opt::big( void ) const
	{
		return opt__big;
	}

	void opt::big( const string_t & value )
	{
		opt__big = value;
	}

	ia::opt::requires opt::require( void ) const
	{
		return opt__require;
	}

	void opt::require( const ia::opt::requires & value )
	{
		opt__require = value;
	}

	ia::opt::types opt::type( void ) const
	{
		return opt__type;
	}

	void opt::type( const ia::opt::types & value )
	{
		opt__type = value;
	}

	::option opt::getgnuopt( void ) const
	{
		::option opt = { nullptr , 0 , nullptr , 0 };

		if ( opt__little )
		{
			opt.name    = ( opt__big.empty( ) ) ? ( nullptr ) : ( opt__big.c_str( ) );
			opt.has_arg = static_cast<int_t>( opt__require );
			opt.flag    = nullptr;
			opt.val     = opt__little;
		}

		return opt;
	}

	void opt::addoptvalue( const string_t & value )
	{
		opt__values.insert( opt__values.end( ) , value );
	}

	string_t opt::str( void ) const
	{
		string_t                            optstr;
		string_t                            delim( ( opt__values.size( ) > size_t( 1 ) ) ? ( " " ) : ( "" ) );
		for ( ia::optvalues::const_iterator i = opt__values.cbegin( ) ; i != opt__values.cend( ) ; ++i )
		{
			optstr = optstr + ( *i ) + delim;
		}

		return optstr;
	}

	std::ostream & operator <<( std::ostream & stream , const ia::opt & opt )
	{
		stream << opt.opt__big << " :";
		for ( ia::optvalues::const_iterator i = opt.opt__values.cbegin( ) ; i != opt.opt__values.cend( ) ; ++i )
		{
			stream << ' ' << ( *i );
		}

		return stream;
	}
}