/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_extended.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 22:19:43 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/07 22:19:45 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_token.h"

t_type	tokenize_get_operator(char *value)
{
	if (ft_strncmp(value, "<<", 2) == 0)
		return (TYPE_HEREDOC);
	else if (ft_strncmp(value, "<", 1) == 0)
		return (TYPE_IN);
	else if (ft_strncmp(value, ">>", 2) == 0)
		return (TYPE_APPEND);
	else if (ft_strncmp(value, ">", 1) == 0)
		return (TYPE_OUT);
	else if (ft_strncmp(value, "||", 2) == 0)
		return (TYPE_TERNARY);
	else if (ft_strncmp(value, "|", 1) == 0)
		return (TYPE_PIPE);
	return (TYPE_EOF);
}

int	tokenize_operator(const char *input, int *i, t_token **token_list)
{
	t_token			*current;

	current = create_node_token();
	if (!current)
	{
		destroy_token_list(token_list);
		return (-1);
	}
	if ((input[0] == '|' && input[1] == '|')
		|| (input[0] == '&' && input[1] == '&')
		|| (input[0] == '>' && input[1] == '>'))
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
	current->type = tokenize_get_operator(current->value);
	append_node_token(token_list, current);
	return (0);
}

int	tokenize_quotes(const char *input, int *i, t_token **token_list)
{
	int				pos;
	char			*value;
	t_token			*current;

	current = create_node_token();
	if (!current)
	{
		destroy_token_list(token_list);
		return (-1);
	}
	pos = 0;
	while (input[pos + 1] && input[pos + 1] != input[0])
		pos += 1;
	if (input[pos + 1] == '\0')
		return (free(current), destroy_token_list(token_list), -1);
	value = ft_substr(input, 1, pos);
	current->type = TYPE_WORD;
	current->value = value;
	append_node_token(token_list, current);
	*i += (pos + 2);
	return (0);
}

int	tokenize_word(const char *input, int *i, t_token **token_list)
{
	int				pos;
	char			*value;
	t_token			*current;

	current = create_node_token();
	if (!current)
	{
		destroy_token_list(token_list);
		return (-1);
	}
	pos = 0;
	while (input[pos] && !ft_isspace(input[pos]))
		pos += 1;
	if (input[pos] == '\0')
		value = ft_substr(input, 0, pos - 1);
	else
		value = ft_substr(input, 0, pos);
	current->type = TYPE_WORD;
	current->value = value;
	append_node_token(token_list, current);
	*i += pos;
	return (0);
}
