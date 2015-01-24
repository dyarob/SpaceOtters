#ifndef ASCIIMG_CLASS_HPP
# define ASCIIMG_CLASS_HPP

# include <fstream>
# include <sstream>
# include <string>
# include <ncurses.h>

class		Asciimg
{
	public:
		Asciimg( void );
		Asciimg( Asciimg const &ai );
		~Asciimg( void );
		Asciimg			&operator=( Asciimg const &ai );

		std::string		s;
		char			*fgc;	//foreground colors
		char			*bgc;	//background colors
		unsigned int	h;
		unsigned int	w;

		void	load( std::string fname );
		void	draw( WINDOW *win, int x, int y ) const;
};

#endif /* !ASCIIMG_CLASS_HPP */
