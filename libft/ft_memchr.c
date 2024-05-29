/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:44:49 by agiraud           #+#    #+#             */
/*   Updated: 2019/12/03 18:31:48 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*block;
	size_t				i;

	block = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (block[i] == (unsigned char)c)
			return (block + i);
		i++;
	}
	return (NULL);
}
