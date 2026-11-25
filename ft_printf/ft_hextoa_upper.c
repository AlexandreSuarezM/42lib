/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:52:51 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/22 14:54:40 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hextoa_upper(unsigned int num)
{
	char	*digits;
	int		i;

	digits = "0123456789ABCDEF";
	i = 0;
	if (num >= 16)
		i += ft_hextoa_upper(num / 16);
	i += ft_putcharc(digits[num % 16]);
	return (i);
}
