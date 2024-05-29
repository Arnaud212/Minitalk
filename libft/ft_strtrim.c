/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:31:21 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 17:11:28 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(&s1[start]);
	if (end != 0)
		while (s1[start + end - 1] && ft_strchr(set, s1[start + end - 1]))
			end--;
	trim = (char *)malloc(sizeof(char) * end + 1);
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, &s1[start], end + 1);
	return (trim);
}
