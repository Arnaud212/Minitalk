/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:13:50 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 12:10:59 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd')
		|| (c == 'i') || (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_is_flag(int c)
{
	return ((c == '-') || (c == '0') || (c == '.') || (c == '*'));
}

int	ft_parse_type(int c, t_flags flags, va_list args)
{
	int	char_count;

	char_count = 0;
	if (c == 'c')
		char_count += ft_print_c(va_arg(args, int), flags);
	else if (c == 's')
		char_count += ft_print_s(va_arg(args, char *), flags);
	else if (c == 'p')
		char_count += ft_print_p(va_arg(args, unsigned long long), flags);
	else if ((c == 'd') || (c == 'i'))
		char_count += ft_print_d_i(va_arg(args, int), flags);
	else if (c == 'u')
		char_count += ft_print_u((unsigned int)va_arg(args, unsigned int),
				flags);
	else if (c == 'x')
		char_count += ft_print_hexa(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		char_count += ft_print_hexa(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		char_count += ft_print_percent(flags);
	return (char_count);
}
