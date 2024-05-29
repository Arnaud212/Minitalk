/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:33:35 by agiraud           #+#    #+#             */
/*   Updated: 2019/12/03 16:27:43 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*v;

	i = 0;
	v = (char *)s;
	while (v[i] != '\0')
	{
		if (v[i] == (char)c)
			return (&v[i]);
		i++;
	}
	if (v[i] == (char)c)
		return (&v[i]);
	return (NULL);
}
