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
	size_t	l = h * w;
	char	*sbuf((char*)malloc(l));

	fgc = (char*)malloc(l);
	bgc = (char*)malloc(l);
	name = fname;
	std::ifstream		f( fname.c_str(), std::ios::in | std::ios::binary );
	f.read( sbuf, l );
	s.append( sbuf );
	f.read( fgc, l );
	f.read( bgc, l );
	f.close();
}

void		Asciimg::save( WINDOW *win )
{
	std::ofstream		f( name.c_str(), std::ios::out | std::ios::binary );
	std::string			ss, sf, sb;
	unsigned int		ih(0), iw(0), i(1);
	chtype				chbuf;

	wmove( win, 1, 1 );
	for (; ih < h;)
	{
		chbuf = mvwinch( win, 1 + ih, 1 + iw );
		ss.push_back( chbuf & A_CHARTEXT );
		sf.push_back( chbuf & A_COLOR >> 8 );
		sb.push_back( chbuf & A_COLOR << 8 );
		++iw;
		if ( iw >= w )
		{
			iw = 0;
			++ih;
			wmove( win, 1 + ih, 1 );
		}
		++i;
	}
	f << ss << sf << sb;
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
