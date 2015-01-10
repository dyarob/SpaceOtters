#include "List.struct.hpp"
#include "WinUI.class.hpp"
#include "WinUI_screen.class.hpp"
#include "EnemyBase.class.hpp"
#include <iostream>
#include <string>
#include <ncurses.h>

int		main( void )
{
	//initscr();
	WinUI_screen *game = new WinUI_screen();
	//wrefresh(game->win);
	EnemyBase	*truc = new EnemyBase( *(new Vector2D(3, 5)), *(new Vector2D(1, 0)) );
	EnemyBase	*truc2 = new EnemyBase( *(new Vector2D(4, 6)), *(new Vector2D(1, 0)) );
	EnemyBase	*truc3 = new EnemyBase( *(new Vector2D(5, 7)), *(new Vector2D(1, 0)) );

	List		*test = new List ( (AUnit*)truc );
	test = test->push(truc2);
	test = test->push(truc3);
	//(void)test;
	refresh();
	mvwprintw(game->win, 1, 1, "x");
	wrefresh(game->win);
	/*
	game->draw(truc);
	wrefresh(game->win);
	*/
	/*
	game->draw_all( test );
	wrefresh(game->win);
	*/
	game->update( test );
	getch();
	endwin();

	/*
	AUnit	*a = new AUnit(1, 2, 3, 4, 5, NULL, NULL, NULL);
	List	*test = new List(bleh);
	List	*voila = new List(a, test);
	voila = voila->push(bluh);
	delete ( voila );
	while (voila)
	{
		std::cout << *voila->o << std::endl;
		voila = voila->next;
	}
	*/
	return (0);
}
