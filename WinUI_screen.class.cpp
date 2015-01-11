#include    "WinUI_screen.class.hpp"



// ----- Adelie modif ----

void	WinUI_screen::update ( List* l )
{
	werase ( win );
	box( win, 0, 0 );
	draw_all ( l );
	wrefresh ( win );
}

void	WinUI_screen::draw_all ( List* l )
{
	while (l)
	{
		draw( l->u );
		l = l->next;
	}
}

void	WinUI_screen::draw ( AUnit* u )
{
	Vector2D v = u->getCoord( );
	mvwprintw( win, v.getX(), v.getY(), "O" );
}

//--------------------

WinUI_screen::WinUI_screen(void) 
: WinUI()
{
}

WinUI_screen::WinUI_screen(unsigned int width, unsigned int height, unsigned int x, unsigned y)
: WinUI(width, height, x, y)
{
}

WinUI_screen::WinUI_screen(WinUI_screen const & src)
: WinUI(src)
{
}

WinUI_screen::~WinUI_screen(void)
{
	this->destroyWin();
}

WinUI_screen &	WinUI_screen::operator=(WinUI_screen const & src) {
	this->_height = src.getHeight();
	this->_width = src.getHeight();
	this->_heightMap = src.getHeight() * 3;
	this->_startX = src.getStartX();
	this->_startY = src.getStartY();
    return *this;
}
