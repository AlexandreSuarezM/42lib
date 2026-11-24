/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:17:07 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/10 18:17:49 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
// probably need to put exits on the function ... but idk how it goes 
static	char	*skip_spaces(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}
static	int	get_sign(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}
static	int	number_len(char *str)
{
	int	len;

	len = 0;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')   //exit maybe ?
			return (-1);
		str++;
		len ++;
	}
	return (len);
}

static	int	compare_positive(char *a, char *b)
{
	int	len_a;
	int	len_b;

	len_a = number_len(a);
	len_b = number_len(b);
	if (len_a > len_b)
		return (1);
	if (len_a < len_b)
		return (-1);
	return (ft_strcmp(a, b));
}

int	compare(char *a, char *b)
{
	int	sign_a;
	int	sign_b;

	a = skip_spaces(a);
	b = skip_spaces(b);
	sign_a = get_sign(&a);
	sign_b = get_sign(&b);
	if (number_len(a) < 0 || number_len(b) < 0) // this is an exit into clear
		return (0); 
	if (sign_a != sign_b)
		return (sign_a - sign_b);
	if (sign_a == -1)
		return (-compare_positive(a, b));
	return (compare_positive(a, b));
}