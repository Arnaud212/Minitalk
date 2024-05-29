/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:06:17 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 17:09:02 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			nb_words++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (nb_words);
}

static char	*ft_fill(char const *s, char c, int i, char *tab)
{
	int		k;

	k = i;
	while (s[k] != c && s[k] != '\0')
		k++;
	tab = malloc(sizeof(char) * (k + 1));
	if (tab == NULL)
	{
		free(tab);
		tab = NULL;
		return (NULL);
	}
	k = 0;
	while (s[i] != c && s[i] != '\0')
		tab[k++] = s[i++];
	tab[k] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		size;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (size + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = -1;
	while (++j < size)
	{
		while (s[i] == c)
			i++;
		tab[j] = ft_fill(s, c, i, tab[j]);
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	tab[j] = 0;
	return (tab);
}
