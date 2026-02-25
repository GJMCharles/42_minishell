/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:49:34 by grcharle          #+#    #+#             */
/*   Updated: 2025/07/30 11:59:36 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*alloc;
	long int	lnmemb;
	long int	lsize;

	lnmemb = (long int) nmemb;
	lsize = (long int) size;
	if ((lnmemb < 0 && lsize != 0) || (lsize < 0 && lnmemb != 0))
		return (0);
	if (INT_MAX < size)
		return ((void *) NULL);
	alloc = malloc(size * nmemb);
	if (!alloc)
		return (0);
	ft_bzero(alloc, (size * nmemb));
	return (alloc);
}
