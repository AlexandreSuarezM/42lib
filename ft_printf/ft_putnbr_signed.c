/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:52:20 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/22 14:54:44 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_signed(int n, int count)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		count += ft_putcharc('-');
		n = -n;
	}
	if (n >= 10)
		count = ft_putnbr_signed(n / 10, count);
	count += ft_putcharc((n % 10) + '0');
	return (count);
}
