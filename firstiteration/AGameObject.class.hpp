#ifndef GAME_OBJECT_HPP
# define GAME_OBJECT_HPP

# include   <fstream>
# include	<iostream>
# include	<list>

# include	"objlist.class.hpp"
# include	"vector2.class.hpp"
# include	"Skin.class.hpp"

class objlist;

class AGameObject {

	protected:
		static Skin* skin;

		static bool	isCollisionPossible(char a, char b);


	public:
		static unsigned int	_cur_id;
		
		static void		print(int, std::list<AGameObject*>);


		unsigned int id;
		unsigned int h;
		unsigned int w;
		int 		 hp;
		unsigned int hp_max;
		int 		 dmg;
    	unsigned int pat;


		Skin*		sk;
		vector2		pos;
		vector2		acc;
		char const	t;

		AGameObject(unsigned int height, unsigned int width, int hp,
				int hp_max, vector2 position, vector2 acceleration, char type);
		virtual ~AGameObject();

		std::ostream	&print(std::ostream &o) const;

		void            move(int const currentFrame);
		void			detect_collision(objlist const &l);


	private:
		/* Bad to no implementation
		AGameObject();
		AGameObject(AGameObject const& copy);
		AGameObject& operator=(AGameObject const& rhs);
		*/
};

std::ostream	&operator<<(std::ostream &o, AGameObject const &go);

#endif // !AGameObject.class.hpp
