#ifndef SPAWNER_CLASS_HPP
# define SPAWNER_CLASS_HPP

# include "objchain.class.hpp"
# include "EnemyBase.class.hpp"

class	Spawner {
	public:
		Spawner();
		~Spawner();

		void	loadLvl(std::string fname);
		void	update(objlist &ol, int currFrame);

	private:
		std::list<objchain*>	chains;
		void	spawn(objlist &ol, vector2 const &pos) const;
};

#endif //!SPAWN_CLASS_HPP
