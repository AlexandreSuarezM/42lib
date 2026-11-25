/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointtoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:53:05 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/25 21:47:52 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointtoa(unsigned long long num)
{
	char		buffer[25];
	char		*digits;
	int			i;
	int			count;

	digits = "0123456789abcdef";
	if (num == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	i = 0;
	write (1, "0x", 2);
	while (num > 0)
	{
		buffer[i++] = digits[num % 16];
		num /= 16;
	}
	count = 0;
	while (--i >= 0)
	{
		count += ft_putcharc(buffer[i]);
	}
	return (count + 2);
}
