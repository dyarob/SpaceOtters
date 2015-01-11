#include "Timer.hpp"
#include <iostream>
#include <thread>
#include <mutex>

void	updatePositions(List *units)
{
	for (List l = units; l; l = l->next) {
		l->u->move(l->u->getDeltaV());
		if (l->u->getCoord().getX() < 0)
			l->delete_one(units, l->u);
	}
}

int main() {

	Timer 			timer(100);
	bool 			running(true);
	unsigned int	currentFrame(0);
	DalayEvent		events;
	List			*units;

	while (running) {
		currentFrame++;
		timer.start();
		events.exec(units);
		updatePositions(units);
		timer.stop();
		timer.wait();
	}
}
