#ifndef _ENV_H
# define _ENV_H

# include <stdio.h>
# include "libft.h"

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}   t_env;

/**
 * env_list.c
 */
void		destroy_env_list(t_env **list);
t_env		*setup_env_list(char **envp);

/**
 * env_node.c
 */
void		delete_node(t_env **list, t_env *node);
void		append_node(t_env **list, t_env *node);
t_env		*create_node(void);

#endif
