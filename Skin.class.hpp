#ifndef SKIN_HPP
# define SKIN_HPP

# include <vector>
# include <ncurses.h>

# include "CONST.h"

class Skin {

	private :

		static int _cId;
		static std::vector<Skin*> reserved_cp;
		static short cfg, cbg;

		Skin& operator=(Skin const&);
		Skin();
		Skin(Skin const&);

	public :

		int		_id;
		int		_fg;
		int		_bg;
		char	_c;

		Skin(char, int, int);
		~Skin();
		int		getId();
		int		getFg();
		int		getBg();
		char	*getCAddr();

		static void init_reserved_cp();
		static void print_cc();
};

#endif
