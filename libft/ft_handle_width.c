/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:13:34 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 12:09:34 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_handle_width(int width, int minimum, int put_zero)
{
	int	char_count;

	char_count = 0;
	while (width - minimum > 0)
	{
		if (put_zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		char_count++;
	}
	return (char_count);
}
