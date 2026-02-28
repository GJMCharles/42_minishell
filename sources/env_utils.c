/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:00:00 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/28 00:00:00 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*env_new(const char *key, const char *value, bool exported)
{
	t_env	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	node->value = value ? ft_strdup(value) : NULL;
	node->exported = exported;
	node->next = NULL;
	return (node);
}

void	env_add_back(t_env **head, t_env *node)
{
	t_env	*it;

	if (!*head)
	{
		*head = node;
		return ;
	}
	it = *head;
	while (it->next)
		it = it->next;
	it->next = node;
}

int	env_from_envp(t_env **dst, char *envp[])
{
	int		i;
	char	*eq;
	char	*key;
	char	*val;
	t_env	*n;

	i = 0;
	while (envp && envp[i])
	{
		eq = ft_strchr(envp[i], '=');
		if (eq)
		{
			key = ft_substr(envp[i], 0, (size_t)(eq - envp[i]));
			val = ft_strdup(eq + 1);
			n = env_new(key, val, true);
			free(key);
			free(val);
			if (!n)
				return (1);
			env_add_back(dst, n);
		}
		i++;
	}
	return (0);
}

t_env	*env_find(t_env *env, const char *key)
{
	while (env)
	{
		if (!ft_strncmp(env->key, key, ft_strlen(key) + 1))
			return (env);
		env = env->next;
	}
	return (NULL);
}

void	env_unset(t_env **env, const char *key)
{
	t_env	*cur;
	t_env	*prev;

	cur = *env;
	prev = NULL;
	while (cur)
	{
		if (!ft_strncmp(cur->key, key, ft_strlen(key) + 1))
		{
			if (prev)
				prev->next = cur->next;
			else
				*env = cur->next;
			free(cur->key);
			free(cur->value);
			free(cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}
