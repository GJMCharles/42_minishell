/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _env.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 14:02:42 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/07 14:02:46 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ENV_H
# define _ENV_H

# include "libft.h"
# include <stdio.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

/**
 * env_list.c
 */
void		destroy_env_list(t_env **list);
t_env		*setup_env_list(char **envp);

/**
 * env_node.c
 */
void		delete_node_env(t_env **list, t_env *node);
void		append_node_env(t_env **list, t_env *node);
t_env		*create_node_env(void);

#endif // _ENV_H
