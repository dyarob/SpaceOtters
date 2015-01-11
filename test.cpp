#include "WinUI.class.hpp"
#include "WinUI_dialogBox.class.hpp"
#include "WinUI_screen.class.hpp"
#include "EnemyBase.class.hpp"
#include "List.struct.hpp"
#include "AUnit.class.hpp"

int main( void ){

	std::cout << "Main_Test" << std::endl;

	WinUI_screen *game = new WinUI_screen(120, 30, 3, 0);
	WinUI_dialogBox *BoxText = new WinUI_dialogBox(120, 7, 33, 0);
	WinUI_dialogBox *BoxHead = new WinUI_dialogBox(120, 3, 0, 0);


	EnemyBase	*truc = new EnemyBase( *(new Vector2D(3, 5)), *(new Vector2D(1, 0)) );
	EnemyBase	*truc2 = new EnemyBase( *(new Vector2D(4, 6)), *(new Vector2D(1, 0)) );
	EnemyBase	*truc3 = new EnemyBase( *(new Vector2D(5, 7)), *(new Vector2D(1, 0)) );
	List		*test = new List ( (AUnit*)truc );

	test = test->push(truc2);
	test = test->push(truc3);
	while (1){
		game->update(test);
		BoxText->translateDialog("Bonjour les gens!");
		BoxHead->fixeDialog(WinUI::keyEvent());
	}
	while (1){
	}
	game->destroyWin();
	BoxHead->destroyWin();
	BoxText->destroyWin();


	endwin();			/* End curses mode		  */
	return 0;
}


           KEY_DOWN        The four arrow keys ...
           KEY_UP
           KEY_LEFT
           KEY_RIGHT