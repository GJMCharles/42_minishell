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

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_BACKGROUND,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_APPEND,
	TOKEN_HEREDOC,
	TOKEN_SEMICOLON
}	t_token_type;

typedef struct s_token
{
	enum e_token_type	type;
	char				*value;
	struct s_token		*next;
}	t_token;

/**
 * tokenize.c
 */
t_token_type	tokenize_get_operator(char *value);
int				tokenize_operator(const char *input, int *i, t_token **list);
int				tokenize_quotes(const char *input, int *i, t_token **list);
int				tokenize_word(const char *input, int *i, t_token **list);
t_token			*tokenize(const char *input);

/**
 * token_list.c
 */
size_t			token_count(t_token *tokens);
void			destroy_token_list(t_token **list);

/**
 * token_node.c
 */
void			append_node_token(t_token **list, t_token *node);
t_token			*create_node_token(void);

#endif // _TOKEN_H
