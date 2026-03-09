/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 14:01:40 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/07 14:02:01 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_token.h"

size_t	token_count(t_token *tokens)
{
	size_t		count;
	t_token		*tmp;

	count = 0;
	tmp = tokens;
	while (tmp)
	{
		tmp = tmp->next;
		count += 1;
	}
	return (count);
}

/**
 * void	destroy_token_list(t_token **list);
 */
void	destroy_token_list(t_token **list)
{
	t_token	*next;

	if (!*list)
		return ;
	while (*list)
	{
		next = (*list)->next;
		if ((*list)->value)
			free((*list)->value);
		free(*list);
		*list = NULL;
		*list = next;
	}
}
