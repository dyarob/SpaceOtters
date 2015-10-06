#ifndef	DEBUG_HPP
# define DEBUG_HPP

# include <fstream>
static std::ofstream	log( "logs", std::ios::out | std::ios::trunc );

#endif
