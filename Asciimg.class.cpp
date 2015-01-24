#include "Asciimg.class.hpp"
#include <stdlib.h>
#include <iostream> // debug

Asciimg::Asciimg( void )
{}

Asciimg::Asciimg( int height, int width )
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
}

Asciimg::Asciimg( Asciimg const &ai )
{
	*this = ai;
}

Asciimg::~Asciimg( void )
{
	//delete [] c;
}

Asciimg		&Asciimg::operator=( Asciimg const &ai )
{
	s = ai.s;
	h = ai.h;
	w = ai.w;
	return *this;
}

void		Asciimg::load( std::string fname )
{
	// text
	std::ifstream		f( fname.c_str(), std::ios::in );
	std::stringstream	buf;
	buf << f.rdbuf();
	s = buf.str();
	f.close();
	// colors
	std::streamsize	l = s.length();
	fgc = (char*)malloc(l);
	bgc = (char*)malloc(l);
	f.open( (fname + "_fcolors").c_str(), std::ios::in | std::ios::binary );
	f.read( fgc, l );
	f.close();
	f.open( (fname + "_bcolors").c_str(), std::ios::in | std::ios::binary );
	f.read( bgc, l );
	f.close();
}

void		Asciimg::draw( WINDOW *win, int y, int x ) const
{
	unsigned int		ih(0), iw(0), i(1);
	wmove( win, y, x );
	for (; ih < h;)
	{
		init_pair(i, fgc[i], bgc[i]);
		wattron( win, COLOR_PAIR(i));
		waddch( win, s.c_str()[i-1] );
		wattroff( win, COLOR_PAIR(i));
		++iw;
		if ( iw >= w )
		{
			iw = 0;
			++ih;
			wmove( win, y + ih, x );
		}
		++i;
	}
}
