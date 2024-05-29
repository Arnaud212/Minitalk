/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:14:41 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 12:17:27 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags	ft_init_struct(void)
{
	t_flags	flags;

	flags.type = 0;
	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.star = 0;
	return (flags);
}

int	ft_parse_flags(const char *str, int i,
				t_flags *flags, va_list args)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_is_type(str[i])
			&& !ft_is_flag(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = ft_flags_dot(str, i + 1, flags, args);
		if (str[i] == '-')
			*flags = ft_flags_minus(*flags);
		if (str[i] == '*')
			*flags = ft_flags_width(args, *flags);
		if (ft_isdigit(str[i]))
			*flags = ft_flags_digit(str[i], *flags);
		if (ft_is_type(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	ft_parse(const char *str, va_list args)
{
	int			i;
	t_flags		flags;
	int			char_count;

	i = 0;
	char_count = 0;
	while (str[i])
	{
		flags = ft_init_struct();
		if (str[i] == '%' && str[i + 1])
		{
			i = ft_parse_flags(str, ++i, &flags, args);
			if (ft_is_type(str[i]))
				char_count += ft_parse_type((char)flags.type, flags, args);
			else if (str[i])
				char_count += ft_putchar(str[i]);
		}
		else if (str[i] != '%')
			char_count += ft_putchar(str[i]);
		i++;
	}
	return (char_count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	const char	*str;
	int			char_count;

	str = ft_strdup(format);
	char_count = 0;
	va_start(args, format);
	char_count += ft_parse(str, args);
	va_end(args);
	free((char *)str);
	return (char_count);
}
