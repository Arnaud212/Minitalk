/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:13:58 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 12:25:53 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_c(char c, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	char_count = ft_handle_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (char_count + 1);
}
