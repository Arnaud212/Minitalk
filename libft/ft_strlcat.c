/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:49:54 by agiraud           #+#    #+#             */
/*   Updated: 2019/12/03 18:37:46 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		j;
	int		res;

	i = 0;
	res = 0;
	while (dst[i] != '\0')
		i++;
	while (src[res] != '\0')
		res++;
	if (dstsize <= i)
		return (res + dstsize);
	else
		res = res + i;
	j = 0;
	while (src[j] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (res);
}
