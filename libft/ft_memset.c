/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 20:41:15 by agiraud           #+#    #+#             */
/*   Updated: 2019/11/15 21:07:23 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*block;
	int				i;

	block = (unsigned char *)b;
	i = 0;
	while (len > 0)
	{
		block[i] = c;
		i++;
		len--;
	}
	return (b);
}
