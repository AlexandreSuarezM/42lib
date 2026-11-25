/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:52:58 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/22 14:54:41 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hextoa(unsigned int num)
{
	char	*digits;
	int		i;

	digits = "0123456789abcdef";
	i = 0;
	if (num >= 16)
		i += ft_hextoa(num / 16);
	i += ft_putcharc(digits[num % 16]);
	return (i);
}
