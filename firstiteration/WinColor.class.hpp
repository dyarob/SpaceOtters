#ifndef WINCOLOR_CLASS_HPP
# define WINCOLOR_CLASS_HPP

# include <vector>
# include <ncurses.h>
# include "CONST.h"
# include "Skin.class.hpp"


class		WinColor
{
	private:
		WinColor( void );
		WinColor( WinColor const &in );
		WinColor	&operator=( WinColor const &in );

		int				id;


		static unsigned int	curs_x;
		static unsigned int	curs_y;
		static int			curr_id;


	public:
		~WinColor( void );
		WinColor( int id_ );

		WINDOW			*win;

		void		draw( void );


		static std::vector<WinColor*>	wc;

		static void		init_wincolors();
		static void		refresh();
		static void		prev();
		static void		next();
		static void		validate_pick();
		static short	getCursColor();
		static void		up();
		static void		down();
		static void		left();
		static void		right();
};

#endif /* !WINCOLOR_CLASS_HPP */
