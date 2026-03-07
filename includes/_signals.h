#ifndef _SIGNALS_H
# define _SIGNALS_H

# include "libft.h"
# include <signal.h>

extern volatile sig_atomic_t	g_exit_status;

void		set_exit_status(int sig);
int			get_exit_status(void);
int		    setup_signals(void);

#endif
