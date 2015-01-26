#ifndef ASCIIMG_CLASS_HPP
# define ASCIIMG_CLASS_HPP

# include <fstream>
# include <sstream>
# include <string>
# include <ncurses.h>

# define IMG_MAX_H 30
# define IMG_MAX_W 120

class		Asciimg
{
	public:
		Asciimg( int height, int width );
		~Asciimg( void );

		std::string		name;
		std::string		s;
		char			*fgc;	//foreground colors
		char			*bgc;	//background colors
		unsigned int	h;
		unsigned int	w;

		void	load( std::string fname );
		void	save( WINDOW *win );
		void	draw( WINDOW *win, int x, int y ) const;

	private:
		Asciimg( void );
		Asciimg( Asciimg const &ai );
		Asciimg			&operator=( Asciimg const &ai );
};

#endif /* !ASCIIMG_CLASS_HPP */
