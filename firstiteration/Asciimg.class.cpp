#include "Asciimg.class.hpp"
#include <stdlib.h>
#include <iostream>

#include "debug.hpp"

Asciimg::Asciimg( void )
	:skins(*(new std::vector<Skin*>()))
{
}

Asciimg::Asciimg( int height, int width )
	:skins(*(new std::vector<Skin*>()))
{
	if ( height < 0 && height > IMG_MAX_H )
	{
		std::cout << "Height is too low or too high." << std::endl;
		throw std::exception();
	}
	if ( width < 0 && width > IMG_MAX_W )
	{
		std::cout << "Width is too low or too high." << std::endl;
		throw std::exception();
	}
	h = height;
	w = width;
	size = h * w;
}

Asciimg::Asciimg( Asciimg const &ai )
	:skins(ai.skins)
{
	*this = ai;
}

Asciimg::~Asciimg( void )
{
}

Asciimg		&Asciimg::operator=( Asciimg const &ai )
{
	//skins = ai.skins;
	h = ai.h;
	w = ai.w;
	size = ai.size;
	name = ai.name;
	return *this;
}

void		Asciimg::load( std::string fname )
{
	char	c;
	short	fg, bg;
	Skin	*faitchier;

	name = fname;
	std::ifstream		f( fname.c_str(), std::ios::in | std::ios::binary );
	for (unsigned int i(0); i<size; ++i)
	{
		f >> c;
		f >> fg;
		f >> bg;
		faitchier =  new Skin( c, fg, bg );
		skins.push_back( faitchier );//new Skin( c, fg, bg ) );
	}
	f.close();
}

void		Asciimg::save( WINDOW *win )
{
	unsigned int		ih(1), iw(0), i(0);
	std::ofstream		f( name.c_str(), std::ios::out | std::ios::binary );

	wmove( win, ih, iw+1 );
	for (; ih <= h; ++i)
	{
		f << *(skins[i]);
		++iw;
		if ( iw >= w )
		{
			iw = 0;
			++ih;
			wmove( win, 1 + ih, 1 );
		}
	}
	f.close();
}

void		Asciimg::draw( WINDOW *win, int y, int x ) const
{
	unsigned int	ih(0), iw(0), i(0);
	unsigned int	x_sav(1), y_sav(1);

	getyx( win, y_sav, x_sav );
	wmove( win, y, x );
	for (; ih < h; ++i)
	{
		wattron( win, COLOR_PAIR(skins[i]->_id));
		waddch( win, skins[i]->_c );
		wattroff( win, COLOR_PAIR(skins[i]->_id));
		++iw;
		if ( iw >= w )
		{
			iw = 0;
			++ih;
			wmove( win, y + ih, x );
		}
	}
	if ( x_sav+1 >= w )
		if ( y_sav <= h )
			wmove( win, y_sav, 1 );
	wmove( win, y_sav, x_sav+1 );
}
