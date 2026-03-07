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

typedef enum e_type
{
	TYPE_WORD,
	TYPE_HEREDOC,
	TYPE_IN,
	TYPE_APPEND,
	TYPE_OUT,
	TYPE_TERNARY,
	TYPE_PIPE,
	TYPE_EOF,
}	t_type;

typedef struct s_token
{
	enum e_type		type;
	char			*value;
	struct s_token	*next;
}	t_token;

/**
 * token_extended.c
 */
t_type		tokenize_get_operator(char *value);
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

#endif
