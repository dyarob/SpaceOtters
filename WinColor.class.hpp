#ifndef WINCOLOR_CLASS_HPP
# define WINCOLOR_CLASS_HPP

# include <vector>
# include <ncurses.h>
# include "CONST.h"


class		WinColor
{
	private:
		WinColor( void );
		WinColor( WinColor const &in );
		WinColor	&operator=( WinColor const &in );

	public:
		~WinColor( void );
		WinColor( int id_ );

		WINDOW	*win;
		int		id;
		unsigned int curs_x;
		unsigned int curs_y;

		void		draw( void );

		static std::vector<WinColor*>	wc;
		static int						curr_id;
		static void	init_wincolors();
		static void	refresh();
};

#endif /* !WINCOLOR_CLASS_HPP */
