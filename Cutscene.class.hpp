#ifndef CUTSCENE_CLASS_HPP
# define CUTSCENE_CLASS_HPP

# include <fstream>
# include "WinUI_dialogBox.class.hpp"

class	Cutscene
{
	public:
		Cutscene(void);
		~Cutscene(void);
		std::fstream const		fs;
};

#endif
