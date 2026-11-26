/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 20:54:14 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/26 20:55:35 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
