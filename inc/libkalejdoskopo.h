#ifndef KALEJDOSKOPO
#define KALEJDOSKOPO

#if defined (__cplusplus)
extern "C" {
#endif

#include <termios.h>

/*external*/
extern void	terminit(void);

/*internal*/
extern int		myputc(int c);
extern struct termios *	tattr_get(void);
extern char *	termbuf_get(void);

#if defined (__cplusplus)
}
#endif

#endif
