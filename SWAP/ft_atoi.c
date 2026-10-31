/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 20:36:57 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/31 19:17:23 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	long int	rt;
	int			sign;

	i = 0;
	rt = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		rt = rt * 10 + (int)(nptr[i] - '0');
		i++;
	}
	if(rt > MAX_INT || -rt < MIN_INT)
		retunr (NULL);
	if(nptr[i] != 0 && rt == 0)
		return (NULL); // this no but flag that reachead a non character . 
	return (rt * sign);
}
/*
#include <stdio.h>

int main ()
{
	int i;
			i = ft_atoi("    -+-+-----+-1235");
	printf("%d\n",i);
	return (42);
}
*/
