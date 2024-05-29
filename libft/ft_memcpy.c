/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:07:47 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 11:43:54 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst2;
	const unsigned char	*src2;
	int					i;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	i = 0;
	if (!n || src == dst)
		return (dst);
	while (n > 0)
	{
		dst2[i] = src2[i];
		i++;
		n--;
	}
	return (dst);
}
