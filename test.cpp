

#include "WinUI.class.hpp"
#include "WinUI_dialogBox.class.hpp"

int main( void ){

	WinUI *game = new WinUI(120, 30, 3, 0);
	WinUI_dialogBox *BoxText = new WinUI_dialogBox(120, 7, 33, 0);
	WinUI_dialogBox *BoxHead = new WinUI_dialogBox(120, 3, 0, 0);

	wrefresh(game->win);
	while (1){
		BoxText->translateDialog("Bonjour les gens!");
		BoxHead->fixeDialog("Titre test");
	}

	game->destroyWin();
	BoxText->destroyWin();

	endwin();			/* End curses mode		  */
	return 0;
}