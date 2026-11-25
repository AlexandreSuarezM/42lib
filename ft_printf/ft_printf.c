/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:53:11 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/25 21:48:58 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		nb_char;
	int		i;

	va_start(args, str);
	i = 0;
	nb_char = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			nb_char += ft_conv(str[i], args);
		}
		else
			nb_char += ft_putcharc(str[i]);
		i++;
	}
	va_end(args);
	return (nb_char);
}
