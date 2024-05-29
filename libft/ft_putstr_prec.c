/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:14:47 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 12:11:39 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_prec(char *str, int prec)
{
	int	i;

	i = 0;
	while (str[i] && i < prec)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
