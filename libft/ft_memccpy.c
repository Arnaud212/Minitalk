/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:15:55 by agiraud           #+#    #+#             */
/*   Updated: 2019/12/03 15:45:38 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst2;
	const unsigned char	*src2;
	int					i;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	i = 0;
	while (n > 0)
	{
		dst2[i] = src2[i];
		if (dst2[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
		n--;
	}
	return (NULL);
}
