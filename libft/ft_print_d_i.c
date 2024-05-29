/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:14:05 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 17:35:34 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_d_i_3(char *str, int nbr2, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (nbr2 < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		char_count += ft_handle_width(flags.dot, ft_strlen(str), 1);
	char_count += ft_putstr_prec(str, ft_strlen(str));
	return (char_count);
}

static int	ft_print_d_i_2(char *str, int nbr2, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (nbr2 == -2147483648 && (flags.dot >= 0 || flags.zero == 1))
		str = ft_strdup("2147483648");
	if (flags.minus == 1)
		char_count += ft_print_d_i_3(str, nbr2, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_handle_width(flags.width, 0, 0);
	}
	else
		char_count += ft_handle_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		char_count += ft_print_d_i_3(str, nbr2, flags);
	return (char_count);
}

int	ft_print_d_i(int nbr, t_flags flags)
{
	char	*str;
	int		nbr2;
	int		char_count;

	nbr2 = nbr;
	char_count = 0;
	if (flags.dot == 0 && nbr == 0)
	{
		char_count += ft_handle_width(flags.width, 0, 0);
		return (char_count);
	}
	if (nbr < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot < 0)
			ft_putstr_prec("-", 1);
		nbr *= -1;
		flags.zero = 1;
		flags.width--;
		char_count++;
	}
	str = ft_itoa(nbr);
	char_count += ft_print_d_i_2(str, nbr2, flags);
	free(str);
	return (char_count);
}
