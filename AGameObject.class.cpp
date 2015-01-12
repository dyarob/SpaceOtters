#include    "Vector2D.class.hpp"
#include    "Weapon.class.hpp"
#include    "AGameObject.class.hpp"

unsigned int AGameObject::_cur_id = 0;
Skin*		 AGameObject::skin( new Skin('0', 7, 0));

bool        checkCondition(char a, char b){
    if ((a == b) || 
		(a == 'a' && b == 'e') || (a == 'e' && b == 'a') ||
		(a == 'm' && b == 'e') || (a == 'e' && b == 'm') ||
		(a == 'm' && b == 'a') || (a == 'a' && b == 'm'))
        return false;
    return true;
}

//----COLLISION ------
List*		AGameObject::detect_collision( List **l, List *thiis, int *score )
{
	Vector2D	voila;
	List		*save = *l;
	List		*resave;
	List		*tmp = thiis->next;
	bool		mod = false;

	while ( *l )
	{
		resave = NULL;
		voila = (*l)->u->getCoord();
        if (checkCondition((*l)->type, thiis->type)){
    		if ( _coord.getX() == voila.getX() && _coord.getY() == voila.getY() && this != (*l)->u )
    		{
                thiis->u->setHp(thiis->u->getHp() - (*l)->u->getDmg());
                if (thiis->u->getHp() <= 0){
                        if (thiis->type == 'e')
                            *score = *score + 5;
                        else if (thiis->type == 'a')
                            *score = *score + 1;
                    save = List::delete_one( save, thiis );
					resave = *l;
					*l = save;
					mod = true;
                }
				if (resave) {
					resave->u->setHp(resave->u->getHp() - thiis->u->getDmg());
					if (resave->u->getHp() <= 0){
                        if (resave->type == 'e')
                            *score = *score + 5;
                        else if (resave->type == 'a')
                            *score = *score + 1;
						*l = List::delete_one( save, *l );
						mod = true;
					}
				}
				else {
					(*l)->u->setHp((*l)->u->getHp() - thiis->u->getDmg());
					if ((*l)->u->getHp() <= 0){
                        if ((*l)->type == 'e')
                            *score = *score + 5;
                        else if ((*l)->type == 'a')
                            *score = *score + 1;
						*l = List::delete_one( save, *l );
						mod = true;
					}
				}
				if (!mod)
					*l = save;
    			return tmp;
    		}
        }
		*l = (*l)->next;
	}
	*l = save;
	return tmp;
}

void		AGameObject::setHp(int hp)
{
	this->_hp = hp;
}
//----------------

AGameObject::AGameObject(unsigned int height, unsigned int width, int hp,
    int hp_max, Vector2D &coord, Vector2D &delta_v)
    : _id(AGameObject::_cur_id++), _height(height), _width(width), _hp(hp),
    _hp_max(hp_max), _dmg(1), _coord(coord), _delta_v(delta_v)
{
	_skin = skin;
}

AGameObject::AGameObject(AGameObject const &src)
    : _coord(src._coord), _delta_v(src._delta_v) {
    *this           = src;
    this->_id++;
}

AGameObject           &AGameObject::operator=(AGameObject const & src) {
    this->_id               = src._id;
    this->_coord            = src._coord;
    this->_delta_v          = src._delta_v;
    this->_height           = src._height;
    this->_width            = src._width;
    this->_hp               = src._hp;
    this->_hp               = src._hp_max;

    return *this;
}

unsigned int    AGameObject::getId(void)      const {
    return this->_id;
}

unsigned int    AGameObject::getHeight(void)  const {
    return this->_height;
}

unsigned int    AGameObject::getWidth(void)   const {
    return this->_width;
}

int    AGameObject::getHp(void)      const {
    return this->_hp;
}

int    AGameObject::getDmg(void)      const {
    return this->_dmg;
}

unsigned int    AGameObject::getHpMax(void)   const {
    return this->_hp_max;
}

Vector2D		&AGameObject::getCoord(void)  const {
    return this->_coord;
}

Vector2D		&AGameObject::getDeltaV(void) const {
    return this->_delta_v;
}

Skin*			AGameObject::getSkin(void) const {
	return _skin;
}

void			AGameObject::setSkin(Skin* skin) {
	_skin = skin;
}

void            AGameObject::setDmg(int dmg){
    _dmg = dmg;
}

void            AGameObject::move(Vector2D &delta_v, int currentFrame) {
    int abs_X;
    int abs_Y;
    int signe_X = 1;
    int signe_Y = 1;

    if (delta_v.getX() < 0) {
        abs_X = delta_v.getX() * -1 ;
        signe_X = -1;
    } else {
        abs_X = delta_v.getX();
    }
    if (abs_X != 0 && currentFrame % abs_X == 0) {
        this->_coord.setX(this->_coord.getX() + (1 * signe_X));
    }

    if (delta_v.getY() < 0) {
        abs_Y = delta_v.getY() * -1 ;
        signe_Y = -1;
    } else {
        abs_Y = delta_v.getY();
    }
    if (abs_Y != 0 && currentFrame % abs_Y == 0) {
        this->_coord.setY(this->_coord.getY() + (1 * signe_Y));
    }
}

void            AGameObject::setCoord(Vector2D &coord) {
    this->_coord = coord;
}

void            AGameObject::setDeltaV(Vector2D &delta_v) {
    this->_delta_v = delta_v;
}

int             AGameObject::getPattern(void) const  {
    return (this->_pattern);
}

AGameObject::~AGameObject() {

}
