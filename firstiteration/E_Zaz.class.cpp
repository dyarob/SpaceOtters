#include    "AUnit.class.hpp"
#include    "Vector2D.class.hpp"
#include    "Weapon.class.hpp"
#include    "E_Zaz.class.hpp"

//Skin*	E_Zaz::skin(new Skin('<', 5, 0));
char		E_Zaz::img[28][43] = 
{
"              `-/shyys+///:.              ",
"          ./ohNMMMMMMMMMMMMNhs:`          ",
"       `/hNMMMMMMMMMMMMMMMMMMMNm+`        ",
"      .hmmmmmmmmmNmNNNMMMMMMNNNNNm+.      ",
"     :mmhssyso+/+/:/+osssyhhhhdmmmmNo`    ",
"    :mh+:-.--..```````.``..-:/+++osdNs    ",
"   .hy+-.-...`````````````...---:::odN+   ",
"   syo/-.-..`````      `````..--:::/sdm.  ",
"  -hs/:-...``` ```     `````..--:::/oyd+  ",
"  /do/-...```           `````..-:::/+shs  ",
"  /d+-.--:++++:-.`     ```..-://::::/oys  ",
"  -d+..::::/+ooo/:.````./osyssoo+/:::ohy  ",
"  `h+--:://///+//:.```.:/+++//+o+//:/odo  ",
" .-o+--:/ssoyy/+o:.```-:+o:oysoys+::/sh+-`",
" :--/-..-////+///--.`.-:/+:/+//+/:::/o/:+`",
" ..//-.`.....---....`.---:::-------:/+/.:`",
" .-s+-...````````...`.--.........--:/o+-.`",
" .-/o:--..``````...``.-:-..``...-:://s/:. ",
" `..++:....```..---..-::---...--::/++o--. ",
"  ..:s:-.....``.-///++++:-------::/++/-.` ",
"   `:d/:-.....--:osssyyo/-------::/+dd+   ",
"    oNy:::--/++/////++///o+/---::/+hMMd   ",
"   +NMN+://://:/::/+++//+/++:-::/+sdMMm`  ",
"  /NMMNyo//+:..--:/+///:--:/:://+ysmMMh`  ",
" :dNNMNhds+o/:...:+s/:-...:++//+syomMMo`  ",
"`ydmmNMdmdhys+-.-/os+:...-:/:-.```.+hNh.  ",
".ddmNMMddmdhhy+//+///:..`````````````./sss",
"omNNNMMhyhddyo:-....````..````..```````.-:"};

E_Zaz::E_Zaz(Vector2D &coord, Vector2D &delta_v, int pattern)
    : AUnit(28, 42, 40, 40, *(new WeaponEnemy()), coord, delta_v) {
        this->_pattern = pattern;
		_skin = skin;
}

E_Zaz::E_Zaz(E_Zaz const &src)
    : AUnit(src) {
    *this           = src;
    this->_id++;
}

E_Zaz           &E_Zaz::operator=(E_Zaz const & src) {
    this->_id               = src._id;
    this->_coord            = src._coord;
    this->_delta_v          = src._delta_v;
    this->_height           = src._height;
    this->_width            = src._width;
    this->_hp               = src._hp;
    this->_hp               = src._hp_max;
    this->_weapon           = src._weapon;
    this->_pattern           = src._pattern;

    return *this;
}

E_Zaz::~E_Zaz() {
    delete &this->_weapon;
}

Projectile	*E_Zaz::shoot( ) const
{
	Vector2D	r = _coord + Vector2D(0, -1);
	return NULL;//( _weapon.fire( new Vector2D(r), new Vector2D(0, -1)));
}
