#ifndef SPAWNER_CLASS_HPP
# define SPAWNER_CLASS_HPP

# include "objlist.class.hpp"
# include "EnemyBase.class.hpp"

class	Spawner {
	public:
		Spawner();
		~Spawner();

		void	spawn(objlist &ol, vector2 const &pos);
};

#endif //!SPAWN_CLASS_HPP
