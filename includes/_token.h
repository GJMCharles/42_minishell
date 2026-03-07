/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _token.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 14:06:40 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/07 14:06:56 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TOKEN_H
# define _TOKEN_H

# include "libft.h"
# include <stdio.h>

typedef enum e_operator
{
	OP_WORD,
	OP_HEREDOC,
	OP_IN,
	OP_APPEND,
	OP_OUT,
	OP_TERNARY,
	OP_PIPE,
	OP_AND,
	OP_BACKGROUND,
	OP_EOF,
}	t_operator;

typedef struct s_token
{
	enum e_operator	type;
	char			*value;
	struct s_token	*next;
}	t_token;

/**
 * token_extended.c
 */
t_operator	tokenize_get_operator(char *value);
int			tokenize_operator(const char *input, int *i, t_token **token_list);
int			tokenize_quotes(const char *input, int *i, t_token **token_list);
int			tokenize_word(const char *input, int *i, t_token **token_list);

/**
 * token_list.c
 */
void		destroy_token_list(t_token **list);
t_token		*tokenize(const char *input);

/**
 * token_node.c
 */
void		append_node_token(t_token **list, t_token *node);
t_token		*create_node_token(void);

#endif // _TOKEN_H
