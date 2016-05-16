#ifndef READOPTS_HPP
#define READOPTS_HPP

#include <list>
#include <vector>
#include <getopt.h>

#include "defs.h++"
#include "opt.h++"


namespace ia
{
	typedef std::list<ia::opt *>		optslist;
	typedef std::vector<::option> 		gnuoptvec;

	class ropts
	{
		public:

		ropts( void );

		ropts( const int_t &			argc ,
				  const char_t * const	argv[] );

		ropts( const int_t &			argc ,
				  const char_t * const	argv[] ,
				  const char_t * const	envp[] );

		virtual ~ropts( void );


		void							addopt( ia::opt * opt );


		void							run( void );


		protected:

		void							getoptarg( const ia::optslist &	list ,
												   string_t &			optstr ,
												   ia::gnuoptvec &		optarr ) const;

		void							getapparg( void );

		void							getargarg( void );


		private:

		ia::optslist					ropts__opts;
		const int_t						ropts__argc;
		char_t * const *				ropts__argv;
		char_t * const *				ropts__envp;
	};
}


#endif // READOPTS_HPP