/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 20:36:57 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/19 21:25:16 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"


// if string compare is positive overflow happende
// unsigned has defined behaviour on overflows
// check the overflow with that one
// make the cumulative 
// check with int max and intt max + 1 for + and -1
static void data_overflow(unsigned int rt, char nptr, int sign, t_list **lst)
{
	unsigned int	num;

	num = rt * 10 + (unsigned int)(nptr - '0');
	if (sign == -1)
		if(num > (((unsigned int)(-1) / 2) + 1))
		{
			write (2, "Error\n", 6);
			ft_lstclear(lst);
			exit (1);
		}
	else
	{
		if(num > (((unsigned int)(-1) / 2)))
		{
			write (2, "Error\n", 6);
			ft_lstclear(lst);
			exit (1);
		}
	}
}

static	int	data_nonum(int r, int lastdigit, t_list **lst)
{	
	if (r == 0 && lastdigit != 0)
	{
		write (2, "Error\n", 6);
		ft_lstclear(lst);
		exit(1);
	}
	if (isnum())
	{
		write (2, "Error\n", 6);
		ft_lstclear(lst);
		exit(1);
	}
	return (0);
}

// aoti modified to take non numbers
int	ft_atoi(const char *nptr,t_list **lst)
{
	int				i;
	unsigned int	rt;
	int				sign;

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
		data_overflow(rt, nptr[i], sign, lst);
		rt = rt * 10 + (int)(nptr[i] - '0');
		i++;
	}
	data_nonum(rt, nptr[i - 1], lst)
	return (rt * sign);
}

//
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
