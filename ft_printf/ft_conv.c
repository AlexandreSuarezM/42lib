/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:52:41 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/25 21:52:02 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putcharc(va_arg(args, int));
	else if (c == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		i = ft_pointtoa((unsigned long long)va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		i = ft_putnbr_signed(va_arg(args, int), 0);
	else if (c == 'u')
		i = ft_putnbr_unsigned(va_arg(args, unsigned int), 0);
	else if (c == 'x')
		i = ft_hextoa(va_arg(args, unsigned int));
	else if (c == 'X')
		i = ft_hextoa_upper(va_arg(args, unsigned int));
	else if (c == '%')
		i = ft_putcharc('%');
	return (i);
}
