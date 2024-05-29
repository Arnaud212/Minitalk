/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:14:35 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 12:14:25 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_u_3(char *nbr, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.dot >= 0)
		char_count += ft_handle_width(flags.dot, ft_strlen(nbr), 1);
	char_count += ft_putstr_prec(nbr, ft_strlen(nbr));
	return (char_count);
}

static int	ft_print_u_2(char *nbr, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_print_u_3(nbr, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(nbr))
		flags.dot = ft_strlen(nbr);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_handle_width(flags.width, 0, 0);
	}
	else
		char_count += ft_handle_width(flags.width, ft_strlen(nbr), flags.zero);
	if (flags.minus == 0)
		char_count += ft_print_u_3(nbr, flags);
	return (char_count);
}

int	ft_print_u(unsigned int nb, t_flags flags)
{
	char	*nbr;
	int		char_count;

	char_count = 0;
	nb = (unsigned int)(4294967295 + 1 + nb);
	if (flags.dot == 0 && nb == 0)
	{
		char_count += ft_handle_width(flags.width, 0, 0);
		return (char_count);
	}
	nbr = ft_u_itoa(nb);
	char_count += ft_print_u_2(nbr, flags);
	free(nbr);
	return (char_count);
}
