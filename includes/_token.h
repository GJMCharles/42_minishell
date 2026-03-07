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

typedef enum e_type
{
	TYPE_WORD,
	TYPE_IN,
	TYPE_OUT,
	TYPE_PIPE,
	TYPE_APPEND,
	TYPE_HEREDOC,
	TYPE_EOF,
}	t_type;

typedef struct s_token
{
	enum e_type		type;
	char			*value;
}   t_token;

#endif
