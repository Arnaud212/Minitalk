/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:38:48 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 16:57:37 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*dest;

	len = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	i = ft_strlen(s2);
	len += i;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		dest[i] = s1[i];
	len = 0;
	while (s2[len] != '\0')
	{
		dest[i + len] = s2[len];
		len++;
	}
	dest[i + len] = '\0';
	return (dest);
}
