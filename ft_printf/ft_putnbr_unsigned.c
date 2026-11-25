/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:53:22 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/22 14:54:44 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n, int count)
{
	if (n >= 10)
		count = ft_putnbr_unsigned(n / 10, count);
	count += ft_putcharc((n % 10) + '0');
	return (count);
}
