#ifndef ASCIIMG_CLASS_HPP
# define ASCIIMG_CLASS_HPP

# include <fstream>
# include <sstream>
# include <string>
# include <vector>
# include <ncurses.h>

# include "Skin.class.hpp"

# define IMG_MAX_H 30
# define IMG_MAX_W 120

class		Asciimg
{
	public:
		Asciimg( int height, int width );
		~Asciimg( void );

		std::string			name;
		std::vector<Skin*>	&skins;
		unsigned int		h;
		unsigned int		w;
		unsigned int		size;

		void	load( std::string fname );
		void	save( WINDOW *win );
		void	draw( WINDOW *win, int x, int y ) const;

	private:
		Asciimg( void );
		Asciimg( Asciimg const &ai );
		Asciimg			&operator=( Asciimg const &ai );
};

#endif /* !ASCIIMG_CLASS_HPP */
