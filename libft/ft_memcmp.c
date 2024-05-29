/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:06:12 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 11:44:26 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*block1;
	const unsigned char	*block2;
	int					i;

	block1 = (unsigned char *)s1;
	block2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (block1[i] != block2[i])
			return (block1[i] - block2[i]);
		n--;
		i++;
	}
	return (0);
}
