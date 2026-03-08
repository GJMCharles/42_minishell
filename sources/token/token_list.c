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

/**
 * t_token	*tokenize(const char *input);
 */
t_token	*tokenize(const char *input)
{
	int				i;
	unsigned char	c;
	t_token			*token_list;
	int				status;

	i = 0;
	token_list = NULL;
	while (input[i])
	{
		c = (unsigned int) input[i];
		if (c == 9 || c == 10 || c == 32)
		{
			i += 1;
			continue ;
		}
		else if (c == ';' || c == '<' || c == '>' || c == '|' || c == '&')
			status = tokenize_operator(input + i, &i, &token_list);
		else if (c == '"' || c == '\'')
			status = tokenize_quotes(input + i, &i, &token_list);
		else
			status = tokenize_word(input + i, &i, &token_list);
		if (status == -1)
			break ;
	}
	return (token_list);
}
