/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:59:27 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/07 13:59:29 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_env.h"

/**
 * 
 */
void	destroy_env_list(t_env **list)
{
	t_env	*next;

	if (!*list)
		return ;
	while (*list)
	{
		next = (*list)->next;
		if ((*list)->key)
			free((*list)->key);
		if ((*list)->value)
			free((*list)->value);
		free(*list);
		*list = NULL;
		*list = next;
	}
}

/**
 * 
 */
t_env	*setup_env_list(char **envp)
{
	int		i;
	t_env	*env_list;
	t_env	*current;
	char	*match;

	i = 0;
	env_list = NULL;
	while (envp && envp[i])
	{
		match = ft_strchr(envp[i], '=');
		if (!match)
			continue ;
		current = create_node();
		if (!current)
			return (destroy_env_list(&env_list), NULL);
		current->key = ft_substr(envp[i], 0, match - envp[i]);
		current->value = ft_strdup(match + 1);
		append_node(&env_list, current);
		i += 1;
	}
	return (env_list);
}
