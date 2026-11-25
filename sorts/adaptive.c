/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 20:54:14 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/24 20:56:04 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"

// adaptive: measures the disorder (0..1) and picks a sort by range
//   0    <= disorder < 0.2  -> selection (simple)   O(n^2)
//   0.2  <= disorder < 0.5  -> chunking  (medium)   O(n*sqrt(n))
//   0.5  <= disorder        -> radix     (complex)  O(n log n)
// returns the flag of the sort it used, so bench can print it
char	*adaptive(t_list **a, t_list **b, int size)
{
	double	dis;

	dis = disorder(*a);
	if (dis < 0.2)
	{
		selectionsort(a, b, size);
		return ("--simple");
	}
	else if (dis < 0.5)
	{
		chunking(a, b, size);
		return ("--medium");
	}
	else
		Radix(a, b, size);
	return ("--complex");
}

// runs the sort of the flag (flag comes from get_flag in push_swap.c)
// returns the flag of the sort actually used (adaptive: the one it picked)
char	*sort_stack(t_list **a, t_list **b, int size, char *flag)
{
	if (ft_strcmp(flag, "--simple") == 0)
		selectionsort(a, b, size);
	else if (ft_strcmp(flag, "--medium") == 0)
		chunking(a, b, size);
	else if (ft_strcmp(flag, "--complex") == 0)
		Radix(a, b, size);
	else
		return (adaptive(a, b, size));
	return (flag);
}
