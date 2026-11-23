/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 20:36:57 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/23 11:51:25 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"

// we get numbers via split 
// so all space separators get cleared
// call atoi clear the separators
// get the sign
// check  num for overflow
// check if the string past sign exists and was a number/z

// unsigned has defined behaviour on overflows unlike int
// check with int max and intt max + 1 for + and -1
// rt is the positive integer that we stack
// rt over or underflows.
static void data_overflow(unsigned int rt, char nptr, int sign, t_list **lst)
{
	unsigned int	num;
	unsigned int	max;

	max = (((unsigned int)(-1) / 2) );
	num = (unsigned int)rt * 10 + (unsigned int)(nptr - '0');
	if (sign == -1)
		max += 1;
	{
		if(num > max)
		{
			write (2, "Error\n", 6);
			ft_lstclear(lst);
			exit (1);
		}
	}
}

// atoi returns int always this cuts the proces if the number misses or 
// this checks if rt was zero was it b ecause 0 was parsed
// when the number ends is it a pure number 123\0 or 123
// for r = 0 nbr -i not good
// because atoi comes after split we can just check that it gets the n
//so now 

static	void	data_nonum(char *content, t_list **lst)
{	
	if(!content || *content == '\0')
	{
		write (2, "Error\n", 6);
		ft_lstclear(lst);
		exit(1);
	}
	while  (*content)
	{
		if (ft_isdigit(*content))
		{
			write (2, "Error\n", 6);
			ft_lstclear(lst);
			exit(1);
		}
		content++;
	}
}

// aoti modified to take non numbers
int	ft_atoi(const char *nptr, t_list **lst)
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
		if (nptr[i] == '+')
			sign = -1;
		i++;
	}
	data_nonum(nptr + i, lst);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		data_overflow(rt, nptr[i], sign, lst);
		rt = rt * 10 - (int)(nptr[i] - '0');
		i++;
	}
	return (((int)rt) * sign);
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
