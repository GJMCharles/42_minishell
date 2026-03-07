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

void		append_node(t_token **list, t_token *node);
t_token		*create_node(void);

void	tokenize_operator(const char *input, int *i, t_token **token_list);
void	tokenize_quotes(const char *input, int *i, t_token **token_list);
void	tokenize_words(const char *input, int *i, t_token **token_list);

/**
 * 
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

void	tokenize_operator(const char *input, int *i, t_token **token_list)
{
	t_token			*current;

	current = create_node();
	if (!current)
	{
		destroy_token_list(token_list);
		return ;
	}
	if ((input[*i] == '|' && input[*i + 1] == '|')
		|| (input[*i] == '&' && input[*i + 1] == '&')
		|| (input[*i] == '>' && input[*i + 1] == '>'))
	{
		current->value = (char *) ft_calloc(sizeof(char), 3);
		ft_memcpy(current->value, input, 2);
		*i += 2;
	}
	else
	{
		current->value = (char *) ft_calloc(sizeof(char), 2);
		ft_memcpy(current->value, input, 1);
		*i += 1;
	}
	current->type = TYPE_EOF;
	append_node(token_list, current);
}

void	tokenize_quotes(const char *input, int *i, t_token **token_list)
{
	(void) input;
	(void) token_list;
	*i += 1;
}

void	tokenize_words(const char *input, int *i, t_token **token_list)
{
	(void) input;
	(void) token_list;
	*i += 1;
}

t_token	*tokenize(const char *input)
{
	int				i;
	unsigned char	c;
	t_token			*token_list;

	i = 0;
	token_list = NULL;
	while (input[i])
	{
		c = (unsigned int) input[i];
		if (ft_isspace(c))
		{
			i += 1;
			continue ;
		}
		else if (c == '<' || c == ';' || c == '|' || c == '&' || c == '>')
			tokenize_operator(input + i, &i, &token_list);
		else if (c == '"' || c == '\'')
			tokenize_quotes(input + i, &i, &token_list);
		else
			tokenize_words(input + i, &i, &token_list);
	}
	return (token_list);
}
