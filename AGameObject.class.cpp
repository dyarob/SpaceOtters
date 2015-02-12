#include    "AGameObject.class.hpp"

//statics
unsigned int	AGameObject::_cur_id = 0;
Skin*			AGameObject::skin( new Skin('0', 7, 0));

std::ostream	&operator<<(std::ostream &o, std::list<AGameObject*> lgo) {
	std::list<AGameObject*>::iterator	it(lgo.begin());
	std::list<AGameObject*>::iterator	end(lgo.end());
	for(; it!=end; ++it) {
		(*it)->print(o);
	}
	return o;
}
std::ostream	&operator<<(std::ostream &o, AGameObject const &go) {
	return go.print(o);
}
std::ostream	&AGameObject::print(std::ostream &o) const {
	o << "GameObject no " << id << std::endl;
	o << "height: " << h << '\t';
	o << "width: " << w << std::endl;
	o << "hp: " << hp << '\t';
	o << "hp_max: " << hp_max << std::endl;
	o << "dmg: " << dmg << std::endl;
	o << "pattern: " << pat << std::endl;
	o << "skin: " << *sk << std::endl;
	// vector2d coord
	// vector2d delta_v
	return o;
}
//!statics

//----COLLISION ------
void		AGameObject::detect_collision(std::list<AGameObject*> const &l)
{
	std::list<AGameObject*>::const_iterator	it(l.begin());
	std::list<AGameObject*>::const_iterator	end(l.end());

	for(; it!=end; ++it) {
		if ((*it)->pos == pos
				&& isCollisionPossible((*it)->t, t)) {
			hp -= (*it)->dmg;
		}
	}
}
//--!COLLISION----

// *structors
AGameObject::~AGameObject() {
}

AGameObject::AGameObject(unsigned int height, unsigned int width, int hp_,
    int hp_max_, vector2 position, vector2 acceleration, char type)
    : id(AGameObject::_cur_id++), h(height), w(width), hp(hp_),
    hp_max(hp_max_), dmg(1), pos(position), acc(acceleration), t(type) {
	sk = skin;
}

/*
AGameObject::AGameObject(AGameObject const &src) {
    *this = src;
    _id++;
}

AGameObject           &AGameObject::operator=(AGameObject const & src) {
    id               = src.id;
    coord            = src.position;
    delta_v          = src.acceleration;
    height           = src.h;
    width            = src.w;
    hp               = src.hp;
    hp_max           = src.hp_max;
    return *this;
}
*/
// !*structors

// functions
void            AGameObject::move(int const currentFrame) {
    int abs_X;
    int abs_Y;
    int signe_X = 1;
    int signe_Y = 1;

    if (acc.x < 0) {
        abs_X = acc.x * -1 ;
        signe_X = -1;
    } else {
        abs_X = acc.x;
    }
    if (abs_X != 0 && currentFrame % abs_X == 0) {
        pos.x += signe_X;
    }

    if (acc.y < 0) {
        abs_Y = acc.y * -1 ;
        signe_Y = -1;
    } else {
        abs_Y = acc.y;
    }
    if (abs_Y != 0 && currentFrame % abs_Y == 0) {
		pos.y += signe_Y;
    }
}

bool        AGameObject::isCollisionPossible(char a, char b) {
    if ((a == b) || 
		(a == 'a' && b == 'e') || (a == 'e' && b == 'a') ||
		(a == 'm' && b == 'e') || (a == 'e' && b == 'm') ||
		(a == 'm' && b == 'a') || (a == 'a' && b == 'm'))
        return false;
    return true;
}
// !functions
