/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:14:25 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 12:12:14 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_percent(t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_putstr_prec("%", 1);
	char_count += ft_handle_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		char_count += ft_putstr_prec("%", 1);
	return (char_count);
}
