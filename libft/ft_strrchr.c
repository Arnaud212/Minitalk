/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:12:06 by agiraud           #+#    #+#             */
/*   Updated: 2019/12/03 16:28:39 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*v;

	i = 0;
	v = (char *)s;
	while (v[i] != '\0')
		i++;
	if (v[i] == (char)c)
		return (&v[i]);
	while (i != 0)
	{
		if (v[i] == (char)c)
			return (&v[i]);
		i--;
	}
	if (v[i] == (char)c)
		return (&v[i]);
	return (NULL);
}
