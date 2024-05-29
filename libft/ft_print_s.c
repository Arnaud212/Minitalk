/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:14:30 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 12:22:33 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_s_2(char *str, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.dot >= 0)
		char_count += ft_putstr_prec(str, flags.dot);
	else
		char_count += ft_putstr_prec(str, ft_strlen(str));
	return (char_count);
}

int	ft_print_s(char *str, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		char_count += ft_print_s_2(str, flags);
	if (flags.dot >= 0)
		char_count += ft_handle_width(flags.width, flags.dot, 0);
	else
		char_count += ft_handle_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		char_count += ft_print_s_2(str, flags);
	return (char_count);
}
