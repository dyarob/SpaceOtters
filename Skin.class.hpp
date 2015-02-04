#ifndef SKIN_HPP
#define SKIN_HPP

#include <ncurses.h>

class Skin {

	private :

		static int _cId;

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
};


#endif
