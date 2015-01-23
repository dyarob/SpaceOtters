#include "Asciimg.class.hpp"
#include <stdlib.h>
#include <iostream> // debug

Asciimg::Asciimg( void )
{}

Asciimg::Asciimg( Asciimg const &ai )
{
	*this = ai;
}

Asciimg::~Asciimg( void )
{
	delete [] c;
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
	char	fg, bg;
	int		i, l;
	l = s.length();
	c = (short*)malloc(l);
	f.open( (fname + "_colors").c_str(), std::ios::in | std::ios::binary );
	for (i=0; i < l; ++i)
	{
		f.read( &fg, 1 );
		f.read( &bg, 1 );
		c[i] = (short)((fg * 255) + bg);	// color index in the general table of all colors
	}
	f.close();
}

void		Asciimg::draw( WINDOW *win, int x, int y ) const
{
	//int		i(0), l(h*w);
	//mvwprintw( win,1, 1, s.c_str() );
	/*
	std::ofstream	f( "coucou" );
		*/
	int		i=900;
	int		l=2000;//h*w;
	for(; i < l; ++i)
	{
	//	f << c[i] << std::endl;
		wattron( win, COLOR_PAIR(i));//c[i]) );
		mvwprintw( win, x, y+i, s.c_str() );
		wattroff( win, COLOR_PAIR(i));//c[i]) );
	}
}
