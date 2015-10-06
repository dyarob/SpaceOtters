#include "WinUI_dialogBox.class.hpp"

WinUI_dialogBox::WinUI_dialogBox(void)
: WinUI(){

}

WinUI_dialogBox::WinUI_dialogBox(unsigned int width, unsigned int height, unsigned int x, unsigned y)
: WinUI(width, height, x, y){

}

WinUI_dialogBox::WinUI_dialogBox(WinUI_dialogBox const & src)
: WinUI(src){

}

WinUI_dialogBox::~WinUI_dialogBox(void) {
}

WinUI_dialogBox &		WinUI_dialogBox::operator=(WinUI_dialogBox const & src) {
	this->_height = src.getHeight();
	this->_width = src.getHeight();
	this->_heightMap = src.getHeight() * 3;
	this->_startX = src.getStartX();
	this->_startY = src.getStartY();
    return *this;
}

void				WinUI_dialogBox::fixeDialog(std::string str, unsigned int x, unsigned int y){
	werase(win);
	box(win, 0, 0);
	unsigned	xp, yp;
	xp = x % getWidth();
	yp = y % getHeight();
	mvwprintw(win, yp, xp, str.c_str());
	wrefresh(win);
	return;
}


void				WinUI_dialogBox::translateDialog(std::string str){
	std::string	test;
	for (unsigned int i = 0; getWidth() > i; i++){
		werase(win);
		box(win, 0, 0);
		mvwprintw(win, getHeight() / 2, getWidth() - i, str.substr(0, i).c_str());
		wrefresh(win);
	}
	return;
}


void				WinUI_dialogBox::tabInfoDial(std::string *tab){
	for (unsigned int i = 0; tab->length() > i;i++){
		std::cout << tab[i] << std::endl;
	}
	return;
}
