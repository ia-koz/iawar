#include "ropts.h++"


namespace ia
{
	ropts::ropts( void )
			:
			ropts__opts( ) ,
			ropts__argc( int_t( 0 ) ) ,
			ropts__argv( nullptr ) ,
			ropts__envp( nullptr )
	{ }

	ropts::ropts( const int_t & argc ,
				  const char_t * const argv[] )
			:
			ropts__opts( ) ,
			ropts__argc( argc ) ,
			ropts__argv( const_cast<char_t * const *>( argv ) ) ,
			ropts__envp( nullptr )
	{ }

	ropts::ropts( const int_t & argc ,
				  const char_t * const argv[] ,
				  const char_t * const envp[] )
			:
			ropts__opts( ) ,
			ropts__argc( argc ) ,
			ropts__argv( const_cast<char_t * const *>( argv ) ) ,
			ropts__envp( const_cast<char_t * const *>( envp ) )
	{ }

	ropts::~ropts( void )
	{ }

	void ropts::addopt( ia::opt * opt )
	{
		ropts__opts.push_back( opt );
	}

	void ropts::getoptarg( const ia::optslist & list , string_t & optstr , ia::gnuoptvec & optarr ) const
	{
		for ( ia::optslist::const_iterator i = ropts__opts.cbegin( ) ; i != ropts__opts.cend( ) ; ++i )
		{
			optarr.push_back( ( *i )->getgnuopt( ) );
			optstr += ( *i )->little( );
			switch ( ( *i )->require( ) )
			{
				case ia::opt::requires::require :
				{
					optstr += ':';
					break;
				}
				case ia::opt::requires::optional :
				{
					optstr += "::";
					break;
				}
				default:
				{
				}
			}
		}
	}

	void ropts::getapparg( void )
	{
		ia::optslist::iterator       optapp;
		for ( ia::optslist::iterator i = ropts__opts.begin( ) ; i != ropts__opts.end( ) ; ++i )
		{
			if ( ( ( *i )->type( ) & ia::opt::types::app ) == ia::opt::types::app )
			{
				optapp = i;
				break;
			}
		}

		if ( ::optind < ropts__argc )
		{
			( *optapp )->addoptvalue( ropts__argv[::optind++] );
		}
	}

	void ropts::getargarg( void )
	{
		ia::optslist::iterator       optapp;
		for ( ia::optslist::iterator i = ropts__opts.begin( ) ; i != ropts__opts.end( ) ; ++i )
		{
			if ( ( ( *i )->type( ) & ia::opt::types::arg ) == ia::opt::types::arg )
			{
				optapp = i;
				break;
			}
		}

		if ( ::optind < ropts__argc )
		{
			while ( ::optind < ropts__argc )
			{
				( *optapp )->addoptvalue( ropts__argv[::optind++] );
			}
		}
	}

	void ropts::run( void )
	{
		if ( ropts__argc == 0 )
		{
			return;
		}

		string_t      gnuoptstr;
		ia::gnuoptvec gnuoptarr;
		getoptarg( ropts__opts , gnuoptstr , gnuoptarr );

		int_t c = int_t( 0 );
		while ( true )
		{
			int option_index = 0;
			c = ::getopt_long( ropts__argc , ropts__argv , gnuoptstr.c_str( ) , gnuoptarr.data( ) ,
							   &option_index );

			if ( c == -1 )
			{
				break;
			}

			bool                               option_find = false;
			for ( ia::optslist::const_iterator i           = ropts__opts.cbegin( ) ; i != ropts__opts.cend( ) ; ++i )
			{
				if ( ( *i )->little( ) == char_t( c ) )
				{
					option_find = true;
					if ( ( *i )->require( ) == ia::opt::requires::none )
					{
						( *i )->addoptvalue( "1" );
					}
					else if ( ( *i )->require( ) == ia::opt::requires::require )
					{
						( *i )->addoptvalue( ::optarg );
					}
					else if ( ( *i )->require( ) == ia::opt::requires::optional )
					{
						( *i )->addoptvalue( ( ( ::optarg ) ? ( ::optarg ) : ( "1" ) ) );
					}
				}
			}
			if ( !option_find )
			{
				::abort( );
			}
		}

		getapparg( );
		getargarg( );
	}
}
