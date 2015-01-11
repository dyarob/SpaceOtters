#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP
# include   <fstream>

#include "Vector2D.class.hpp"
#include "Skin.class.hpp"
#include "List.struct.hpp"


class List;

class AGameObject {

	protected :

		static Skin* skin;
		unsigned int _id;
		unsigned int _height;
		unsigned int _width;
		unsigned int _hp;
		unsigned int _hp_max;
    	unsigned int _pattern;

		Skin*		 _skin;
		Vector2D	 &_coord;
		Vector2D	 &_delta_v;

	public	:

		static unsigned int	_cur_id;
		AGameObject(unsigned int height, unsigned int width, int hp, int hp_max,
				Vector2D &coord, Vector2D &delta_v);
		AGameObject();
		AGameObject(AGameObject const& copy);
		AGameObject& operator=(AGameObject const& rhs);
		~AGameObject();

		unsigned int    getId(void)             const;
		unsigned int    getHeight(void)         const;
		unsigned int    getWidth(void)          const;
		unsigned int    getHp(void)             const;
		unsigned int    getHpMax(void)          const;
		Vector2D 		&getCoord(void)         const;
		Vector2D 		&getDeltaV(void)        const;
   		int		        getPattern(void)        const;
		Skin*			getSkin(void)			const;

		void            setDeltaV(Vector2D &delta_v);
		void			setHp(unsigned int hp);
		void			setSkin(Skin*);

		void            move(Vector2D &delta_v, int currentFrame);
		List*			detect_collision( List **l, List *thiis );
};

#endif
