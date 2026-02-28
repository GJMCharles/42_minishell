/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:00:00 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/28 00:00:00 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_env(t_env *env)
{
	while (env)
	{
		if (env->exported && env->value)
		{
			ft_putstr_fd(env->key, STDOUT_FILENO);
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putstr_fd(env->value, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		env = env->next;
	}
	return (0);
}

static void	print_export_line(const t_env *e)
{
	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	ft_putstr_fd(e->key, STDOUT_FILENO);
	if (e->value)
	{
		ft_putstr_fd("=\"", STDOUT_FILENO);
		ft_putstr_fd(e->value, STDOUT_FILENO);
		ft_putstr_fd("\"", STDOUT_FILENO);
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
}

static void	bi_fill_arr(t_env **arr, t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		arr[i] = env;
		env = env->next;
		i++;
	}
}

static void	bi_sort_export(t_env **arr, int n)
{
	int		i;
	int		j;
	t_env	*tmp;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (ft_strncmp(arr[i]->key, arr[j]->key, 1000) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	bi_export_print(t_env *env)
{
	int		n;
	int		i;
	t_env	**arr;
	t_env	*it;

	n = 0;
	it = env;
	while (it)
	{
		n++;
		it = it->next;
	}
	if (n == 0)
		return (0);
	arr = malloc(sizeof(*arr) * (size_t)n);
	if (!arr)
		return (1);
	bi_fill_arr(arr, env);
	bi_sort_export(arr, n);
	i = 0;
	while (i < n)
		print_export_line(arr[i++]);
	free(arr);
	return (0);
}
