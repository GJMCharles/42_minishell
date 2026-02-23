/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 07:43:28 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/23 07:44:29 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_recalloc(void *s, size_t nmemb, size_t p_size, size_t n_size)
{
	void	*dest;

	if (!s)
		return ((void *) 0);
	dest = ft_calloc(nmemb, n_size);
	if (!dest)
	{
		free(s);
		return ((void *) 0);
	}
	if (p_size < n_size)
		ft_memcpy(dest, s, p_size);
	else
		ft_memcpy(dest, s, n_size);
	free(s);
	return (dest);
}
