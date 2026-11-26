/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 20:36:57 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/26 21:10:25 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"


static void data_overflow(int rt, char nptr, int sign, t_list **lst, char **args)
{
	int	d;
	int	min;

	min = -(int)(((unsigned int)(-1) / 2)) - 1;
	d = nptr - '0';
	if (rt < (min + d) / 10
		|| (sign == -1 && rt * 10 - d == min))
	{
		write (2, "Error\n", 6);
		ft_lstclear(lst, args);
		exit (1);
	}
}

// atoi returns int always this cuts the proces if the number misses or 
// this checks if rt was zero was it b ecause 0 was parsed
// when the number ends is it a pure number 123\0 or 123
// for r = 0 nbr -i not good
// because atoi comes after split we can just check that it gets the n
//so now 

static	void	data_nonum(const char *content, t_list **lst, char **args)
{	
	if(!content || *content == '\0')
	{
		write (2, "Error\n", 6);
		ft_lstclear(lst, args);
		exit(1);
	}
	while  (*content)
	{
		if (ft_isdigit(*content))
		{
			write (2, "Error\n", 6);
			ft_lstclear(lst, args);
			exit(1);
		}
		content++;
	}
}

// aoti modified to take non numbers
// rt is always <= 0, sign turns it back at the end:
// no sign or '+' -> sign = -1 (rt * -1 is positive)
// '-'            -> sign = 1  (rt stays negative)
int	ft_atoi(const char *nptr, t_list **lst, char **args)
{
	int	i;
	int	rt;
	int	sign;

	i = 0;
	rt = 0;
	sign = -1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = 1;
		i++;
	}
	data_nonum(nptr + i, lst, args);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		data_overflow(rt, nptr[i], sign, lst, args);
		rt = rt * 10 - (nptr[i] - '0');
		i++;
	}
	return (rt * sign);
}

