/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:29:54 by agiraud           #+#    #+#             */
/*   Updated: 2019/12/04 17:08:07 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst2;
	char	*src2;
	size_t	i;

	if (src == dst)
		return (dst);
	dst2 = (char *)dst;
	src2 = (char *)src;
	if (src2 < dst2)
	{
		i = len;
		while (i-- > 0)
			dst2[i] = src2[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	return (dst);
}
