#ifndef SKIN_HPP
# define SKIN_HPP

# include <vector>
# include <ncurses.h>
# include <fstream>

# include "CONST.h"

class Skin {

	private :
		// not declared in .cpp
		//Skin( void );
		//Skin( Skin const& );
		//Skin&	operator=( Skin const& );

		int		_fg;
		int		_bg;

		static int _cId;
		static std::vector<Skin*> reserved_cp;

	public :
		~Skin( void );
		Skin( char, int, int );

		int		_id;
		char	_c;

		std::ofstream	&printTo( std::ofstream &o ) const;
		void	redefine_fg( short fg );
		void	redefine_bg( short bg );

		static short	cfg, cbg;
		static void		init_reserved_cp();
		static void		print_cc();
};

std::ofstream	&operator<<( std::ofstream &o, Skin const &sk );

#endif
