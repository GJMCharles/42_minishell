/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:00:00 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/28 00:00:00 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*cd_get_path(t_minishell *shell, char **args)
{
	t_env	*home;

	if (args[1])
		return (args[1]);
	home = env_find(shell->env, "HOME");
	if (!home)
	{
		ft_putstr_fd("cd: HOME not set\n", STDERR_FILENO);
		return (NULL);
	}
	return (home->value);
}

static void	cd_update_oldpwd(t_env *env, const char *old_pwd)
{
	t_env	*node;

	if (!old_pwd)
		return ;
	node = env_find(env, "OLDPWD");
	if (node)
	{
		free(node->value);
		node->value = ft_strdup(old_pwd);
	}
}

static void	cd_update_pwd(t_env *env)
{
	char	buf[BUFFER_SIZE];
	t_env	*node;

	if (!getcwd(buf, BUFFER_SIZE))
		return ;
	node = env_find(env, "PWD");
	if (node)
	{
		free(node->value);
		node->value = ft_strdup(buf);
	}
}

int	change_directory(t_minishell *shell, char **args)
{
	char	*path;
	char	*old_pwd;
	t_env	*pwd_node;

	path = cd_get_path(shell, args);
	if (!path)
		return (1);
	pwd_node = shell->env ? env_find(shell->env, "PWD") : NULL;
	old_pwd = pwd_node ? pwd_node->value : NULL;
	if (chdir(path) == -1)
		return (perror("cd"), 1);
	cd_update_oldpwd(shell->env, old_pwd);
	cd_update_pwd(shell->env);
	return (0);
}
