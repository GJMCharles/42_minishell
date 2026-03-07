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

t_token	*tokenize(const char *input)
{
	int				i;
	unsigned char	c;
	t_token			*token_list;
	t_token			*current;

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
			tokenize_operator(input, &i, &token_list);
		else if (c == '"' || c == '\'')
			tokenize_quotes(input, &i, &token_list);
		else
			tokenize_words(input, &i, &token_list);
	}
	return (token_list);
}

// char	*tokenize_word(const char *start, char *ptr)
// {
// 	int		len;
// 	char	*word;

// 	len = ptr - start;
// 	word = (char *) ft_calloc(sizeof(char), len + 1);
// 	if (!word)
// 		return (NULL);
// 	word = (char *) ft_memcpy(word, start, len);
// 	return (word);
// }

// void	tokenize_unknown(const char **input, t_ui *pos, t_token *token)
// {
// 	const char	*start;
// 	t_uc		c;

// 	start = *input;
// 	c = (t_uc) **input;
// 	while (c && !ft_isspace(c) && c != ';' && c != '|' && c != '&')
// 	{
// 		*input += 1;
// 		c = (t_uc) **input;
// 	}
// 	token->type = TOKEN_WORD;
// 	token->value = tokenize_word(start, (char *) *input);
// 	*input += 1;
// 	*pos += 1;
// }

// void	tokenize_quotes(const char **input, t_ui *pos, t_token *tokens)
// {
// 	t_uc		quote;
// 	const char	*start;

// 	quote = (t_uc) **input;
// 	*input += 1;
// 	start = *input;
// 	while (**input && **input != quote)
// 		*input += 1;
// 	if (**input == '\0')
// 	{
// 		ft_putendl_fd("error unterminated quote", STDERR_FILENO);
// 		free_tokens(tokens);
// 		return ;
// 	}
// 	tokens[*pos].type = TOKEN_WORD;
// 	tokens[*pos].value = tokenize_word(start, (char *) *input);
// 	*input += 1;
// 	*pos += 1;
// }

// void	tokenize_operator(const char **input, t_ui *pos, t_token *token)
// {
// 	t_uc		c;
// 	char		str[2];
// 	const char	*ptr;

// 	c = (t_uc) **input;
// 	str[0] = c;
// 	str[1] = '\0';
// 	ptr = *input;
// 	token->type = TOKEN_OPERATOR;
// 	token->value = ft_strdup(str);
// 	if ((c == '|' && *(ptr + 1) == '|')
// 		|| (c == '&' && *(ptr + 1) == '&')
// 		|| (c == '>' && *(ptr + 1) == '>'))
// 	{
// 		token->value = ft_recalloc(token->value, sizeof(char), 1, 3);
// 		ft_memcpy(token->value + 1, str, 1);
// 		*input += 1;
// 	}
// 	*input += 1;
// 	*pos += 1;
// }
	// t_ui		pos;
	// const char	*p;
	// t_token		*tokens;

	// pos = 0;
	// p = input;
	// tokens = (t_token *) ft_calloc(sizeof(t_token), MAX_TOKEN);
	// if (!tokens)
	// 	return (perror("Error"), NULL);
	// while (*p)
	// {
	// 	if (ft_isspace(*p))
	// 		p += 1;
	// 	else if (*p == '<' || *p == ';' || *p == '|' || *p == '&' || *p == '>')
	// 		tokenize_operator(&p, &pos, &tokens[pos]);
	// 	else if (*p == '"' || *p == '\'')
	// 		tokenize_quotes(&p, &pos, tokens);
	// 	else
	// 		tokenize_unknown(&p, &pos, &tokens[pos]);
	// }
	// tokens[pos].type = TOKEN_EOF;
	// tokens[pos].value = NULL;
