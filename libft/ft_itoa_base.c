/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:13:42 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 17:12:34 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_treat_base(unsigned long long nbr,
						int base, char *str, int i)
{
	while (nbr != 0)
	{
		if (nbr % base < 10)
			str[i - 1] = (nbr % base) + 48;
		else
			str[i - 1] = (nbr % base) + 55;
		nbr /= base;
		i--;
	}
	return (str);
}

char	*ft_itoa_base(unsigned long long value, int base)
{
	char				*str;
	unsigned long long	nbr;
	int					i;

	i = 0;
	nbr = value;
	if (value == 0)
		return (ft_strdup("0"));
	while (value != 0)
	{
		value /= base;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	str = ft_treat_base(nbr, base, str, i);
	return (str);
}
