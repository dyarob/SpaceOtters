#ifndef KALEJDOSKOPO
# define KALEJDOSKOPO

#include <termios.h>

void	terminit(void);

/*internal*/
int		myputc(int c);
struct termios *	tattr_get(void);
char *	termbuf_get(void);

#endif
