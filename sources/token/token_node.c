/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:49:49 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/07 13:58:39 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_token.h"

/**
 * void	append_node_token(t_token **list, t_token *node)
 */
void	append_node_token(t_token **list, t_token *node)
{
	t_token	*tmp;

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
 * t_token	*create_node_token(void);
 */
t_token	*create_node_token(void)
{
	t_token	*node;

	node = (t_token *) ft_calloc(sizeof(t_token), 1);
	if (!node)
		return (perror("failed to allocate 'struct s_token'"), NULL);
	node->value = NULL;
	node->next = NULL;
	return (node);
}
