#include    "WinUI.class.hpp"

WinUI::WinUI(void)
: _width(120), _height(30), _startX(0), _startY(0), _heightMap(60){
	initscr();
	curs_set(0);
//	cbreak();
	this->win = this->createWin();
}

WinUI::WinUI(unsigned int width, unsigned int height, unsigned int x, unsigned y)
: _width(width), _height(height), _startX(x), _startY(y), _heightMap(height * 3){
	this->win = this->createWin();
	curs_set(0);
	initscr();
//	cbreak();
	this->win = this->createWin();
}

WinUI::WinUI(WinUI const & src)
: _width(src.getWidth()), _height(src.getHeight()), _startX(src.getStartX()), 
_startY(src.getStartY()), _heightMap(src.getHeight() * 3){
	curs_set(0);
	initscr();
//	cbreak();
	this->win = this->createWin();
}

WinUI::~WinUI(void) {
	this->destroyWin();
}

WinUI &				WinUI::operator=(WinUI const & src) {
	this->_height = src.getHeight();
	this->_width = src.getHeight();
	this->_heightMap = src.getHeight() * 3;
	this->_startX = src.getStartX();
	this->_startY = src.getStartY();
    return *this;
}

WINDOW			*WinUI::createWin(void){

	WINDOW *local_win;
	local_win = newwin(this->getHeight(), this->getWidth(), this->getStartX(), this->getStartY());
	box(local_win, 0 , 0); 
	wrefresh(local_win); 		
	return local_win;
}

std::string		WinUI::keyEvent(void){
	int  ch  = getch();
	switch (ch){
		case KEY_BACKSPACE:
			return "espace";
		break;
		case KEY_DOWN:
			return "bas";
		break;
		case KEY_UP:
			return "haut";
		break;
		case KEY_LEFT:
			return "gauche";
		break;
		case KEY_RIGHT:
			return "droite";
		break;
	}
	return "RAS";
}

void            WinUI::destroyWin(void){
	wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(win);
	delwin(win);	
}

unsigned int    WinUI::getWidth(void) const{
	return this->_width;
}

unsigned int    WinUI::getHeight(void) const{
	return this->_height;
}

unsigned int    WinUI::getStartX(void) const{
	return this->_startX;
}

unsigned int    WinUI::getStartY(void) const{
	return this->_startY;
}
