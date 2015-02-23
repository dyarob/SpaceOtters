#include "objchain.class.hpp"

objchain::objchain(int startFrame, vector2 &startPos, unsigned short number,
		unsigned short delay, unsigned short pattern) {
	sf = startFrame;
	sp.x = startPos.x;
	sp.y = startPos.y;
	nu = number;
	F = delay;
	pat = pattern;
}

//private
objchain::objchain() {
}

objchain::~objchain() {
	//need free mem here
}
