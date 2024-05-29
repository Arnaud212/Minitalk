/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:14:19 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 12:24:39 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_p_2(char *str, t_flags flags)
{
	int	char_count;

	char_count = 0;
	char_count += ft_putstr_prec("0x", 2);
	char_count += ft_handle_width(flags.dot, ft_strlen(str), 1);
	char_count += ft_putstr_prec(str, ft_strlen(str));
	return (char_count);
}

int	ft_print_p(unsigned long long p, t_flags flags)
{
	char	*str;
	int		char_count;

	char_count = 0;
	if (p == 0 && flags.dot == 0)
	{
		if (flags.minus == 1)
			char_count += ft_putstr_prec("0x", 2);
		char_count += ft_handle_width(flags.width - 2, 0, 0);
		if (flags.minus == 0)
			char_count += ft_putstr_prec("0x", 2);
		return (char_count);
	}
	str = ft_itoa_base(p, 16);
	str = ft_str_tolower(str);
	if ((size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		char_count += ft_print_p_2(str, flags);
	char_count += ft_handle_width(flags.width, ft_strlen(str) + 2, 0);
	if (flags.minus == 0)
		char_count += ft_print_p_2(str, flags);
	free(str);
	return (char_count);
}
