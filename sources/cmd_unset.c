/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:00:00 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/28 00:00:00 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_valid_identifier(const char *s)
{
	size_t	i;

	i = 0;
	if (!s || !s[0] || !(ft_isalpha((int)s[0]) || s[0] == '_'))
		return (false);
	while (s[++i])
	{
		if (!(ft_isalnum((int)s[i]) || s[i] == '_'))
			return (false);
	}
	return (true);
}

int	bi_unset(t_env **env, char **argv)
{
	int	status;
	int	i;

	status = 0;
	if (!argv || !argv[0])
		return (0);
	i = 1;
	while (argv[i])
	{
		if (!is_valid_identifier(argv[i]))
		{
			ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
			ft_putstr_fd(argv[i], STDERR_FILENO);
			ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
			status = 1;
		}
		else
			env_unset(env, argv[i]);
		i++;
	}
	return (status);
}
