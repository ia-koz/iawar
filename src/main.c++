#include <iostream>
#include <unistd.h>
#include <list>
#include <fcntl.h>
#include <error.h>

#include "defs.h++"
#include "opt.h++"
#include "ropts.h++"
#include "point.h++"


typedef std::list<pthread_t> thrslist;

struct thrdata_t
{
	thrdata_t( bool_t * IsBreak , const string_t & Path )
		:
		thrdata__isbreak( IsBreak ) ,
		thrdata__path( Path )
	{ }

	bool_t * thrdata__isbreak;
	string_t thrdata__path;
};

void * readfile( void * data );

int main( const int_t argc , const char_t * const argv[] , const char_t * const envp[] )
{
	int_t margc       = 0;
	while ( ( argc - margc ) > 0 )
	{
		std::cout << argv[margc++] << std::endl;
	}


	ia::opt appopt( '#' , "app" , ia::opt::requires::none , ia::opt::types::app );
	ia::opt fileopt( 'f' , "file" , ia::opt::requires::require , ia::opt::types::opt | ia::opt::types::arg );

	ia::ropts optreader( argc , argv );
	optreader.addopt( &appopt );
	optreader.addopt( &fileopt );

	optreader.run( );

	std::cout << "Параметры командной строки" << std::endl;
	std::cout << appopt << std::endl;
	std::cout << fileopt << std::endl;


	int_t     result;
	pthread_t pt;
	thrslist  threadslist;
	bool_t    isbreak = false;
	thrdata_t td( &isbreak , fileopt.str( ) );
	if ( appopt.str( ) == "read" )
	{
		result = ::pthread_create( &pt , NULL , readfile , &td );
		if ( result != 0 )
		{
			::perror( "Creating the thread" );
			return EXIT_FAILURE;
		}
	}


	ia::point p( ia::point::coord_t( 1 ) , ia::point::coord_t( 2 ) , ia::point::coord_t( 3 ) );
	std::cout << p << std::endl;
	ia::point pp( ia::point::coord_t( 1 ) , ia::point::coord_t( 2 ) , ia::point::coord_t( 3 ) );
	std::cout << pp << std::endl;
	std::cout << ( p + pp ) << std::endl;
	std::cout << ( p - pp ) << std::endl;
	std::cout << ( p == pp ) << std::endl;
	std::cout << ( p != pp ) << std::endl;
	std::cout << ( p = pp + p ) << std::endl;


	// Основной цикл программы
	while ( true )
	{
		std::cout << "Enter:" << std::endl;
		string_t input;
		while ( std::cin >> input )
		{
			if ( input == "q" )
			{
				isbreak = true;
				break;
			}
		}
		if ( std::cin.fail( ) || input == "q" )
		{
			isbreak = true;
			break;
		}
	}


	// Ждём присоединения потоков
	for ( thrslist::iterator it = threadslist.begin( ) ; it != threadslist.end( ) ; ++it )
	{
		::printf( "Start joining thread\n" );
		result = ::pthread_join( *it , NULL );
		if ( result != 0 )
		{
			::perror( "Joining thread" );
			return EXIT_FAILURE;
		}
	}


	std::cout << "Exit." << std::endl;


	return EXIT_SUCCESS;
}

void * readfile( void * data )
{
	// Наши данные
	thrdata_t d = *( static_cast<thrdata_t *>( data ) );

	int_t fd = ::open( d.thrdata__path.c_str( ) , O_RDONLY );
	if ( fd == -1 )
	{
		::perror( "open" );
		return nullptr;
	}

	ssize_t result;
	dword_t buf;
	while ( !( *( d.thrdata__isbreak ) ) )
	{
		buf    = dword_t( 0u );
		result = ::read( fd , &buf , sizeof( buf ) );
		if ( result == -1 )
		{
			error_t err = errno;
			if ( err == EINTR )
			{
				continue;
			}
			else if ( err == EOF )
			{
				*( d.thrdata__isbreak ) = true;
			}

			::perror( "read" );
			return nullptr;
		}

		std::cout << std::hex << "Was read " << result << " bytes. " << "buf = " << buf << std::endl;
	}

	::close( fd );


	return nullptr;
}