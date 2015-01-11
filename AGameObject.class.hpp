#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP
# include   <fstream>

#include "Vector2D.class.hpp"
#include "List.struct.hpp"


class List;

class AGameObject {

	protected :

		unsigned int _id;
		unsigned int _height;
		unsigned int _width;
		unsigned int _hp;
		unsigned int _hp_max;
		char		 _skin;
		int			 _fgColor;
		int			 _bgColor;
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
		char			getSkin(void)			const;
		int				getFgColor(void)		const;
		int				getBgColor(void)		const;
		void            move(Vector2D &delta_v, int currentFrame);
		void            setDeltaV(Vector2D &delta_v);
		void			setHp(unsigned int hp);

		List*			detect_collision( List **l, List *thiis );
};

#endif
