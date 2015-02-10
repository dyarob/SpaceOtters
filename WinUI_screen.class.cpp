#include    "WinUI_screen.class.hpp"

void	WinUI_screen::update ( std::list<AGameObject*> &l )
{
	werase ( win );
	box( win, 0, 0 );
	draw_all ( l );
	wrefresh ( win );
}

void	WinUI_screen::draw_all ( std::list<AGameObject*> const &l ) const
{
	std::list<AGameObject*>::const_iterator	it(l.begin());
	std::list<AGameObject*>::const_iterator	end(l.end());
	for (; it!=end; ++it) {
		draw( *it );
	}
}

void	WinUI_screen::draw ( AGameObject* const &u ) const
{
	Vector2D v = u->getCoord();
	if (has_colors()) {
		if (u->getSkin()) {
			u->getSkin()->init_cp();
			wattron(win, COLOR_PAIR(u->getSkin()->_id));
			int	w = u->getWidth();
			if ( w == 1 ) {
				char c = u->getSkin()->_c;
				mvwaddch( win, v.getX(), v.getY(), c);
			}
			else {		// Zaz
				int h = u->getHeight();
				//int j;
				char *c;
				for (int i = 0; i < h; ++i) {
					c = ((E_Zaz*)u)->img[i];
					mvwaddch( win, v.getX() + i, v.getY(), *c );
				}
			}
			wattroff(win, COLOR_PAIR(u->getSkin()->_id));
		}
	}
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
}

WinUI_screen &	WinUI_screen::operator=(WinUI_screen const & src) {
	this->_height = src.getHeight();
	this->_width = src.getHeight();
	this->_heightMap = src.getHeight() * 3;
	this->_startX = src.getStartX();
	this->_startY = src.getStartY();
    return *this;
}
