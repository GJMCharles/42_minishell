/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:59:35 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/07 13:59:37 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_env.h"

/**
 * void	delete_node_env(t_env **list, t_env *node);
 */
void	delete_node_env(t_env **list, t_env *node)
{
	t_env	*tmp;
	t_env	*next;

	if (!node || !*list)
		return ;
	tmp = *list;
	while (tmp && tmp->next != node)
		tmp = tmp->next;
	if (tmp && tmp->next && tmp->next == node)
	{
		next = tmp->next->next;
		free(tmp->next->key);
		free(tmp->next->value);
		free(tmp->next);
		tmp->next = next;
	}
}

/**
 * void	append_node_env(t_env **list, t_env *node);
 */
void	append_node_env(t_env **list, t_env *node)
{
	t_env	*tmp;

	if (!node)
		return ;
	if (!*list)
	{
		*list = node;
		return ;
	}
	tmp = *list;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

/**
 * t_env	*create_node_env(void);
 */
t_env	*create_node_env(void)
{
	t_env	*node;

	node = (t_env *) ft_calloc(sizeof(t_env), 1);
	if (!node)
		return (perror("failed to allocate 'struct s_env'"), NULL);
	node->key = NULL;
	node->value = NULL;
	node->next = NULL;
	return (node);
}

///
// /**
//  * t_type	tokenize_get_operator(char *value);
//  */
// t_type	tokenize_get_operator(char *value)
// {
// 	if (ft_strncmp(value, "<<", 2) == 0)
// 		return (OP_HEREDOC);
// 	else if (ft_strncmp(value, "<", 1) == 0)
// 		return (OP_IN);
// 	else if (ft_strncmp(value, ">>", 2) == 0)
// 		return (OP_APPEND);
// 	else if (ft_strncmp(value, ">", 1) == 0)
// 		return (OP_OUT);
// 	else if (ft_strncmp(value, "||", 2) == 0)
// 		return (OP_TERNARY);
// 	else if (ft_strncmp(value, "|", 1) == 0)
// 		return (OP_PIPE);
// 	else if (ft_strncmp(value, "&&", 2) == 0)
// 		return (OP_AND);
// 	else if (ft_strncmp(value, "&", 1) == 0)
// 		return (OP_BACKGROUND);
// 	return (TOKEN_EOF);
// }
