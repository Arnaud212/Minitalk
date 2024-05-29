/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:40:42 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 17:11:58 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*dest;
	size_t				i;
	size_t				j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	while (i < start)
		i++;
	while (s[i] != '\0' && j < len)
	{
		dest[j] = s[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
