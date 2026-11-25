/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selectionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:59:34 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/24 21:07:21 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
// Selection sort. Goal: a sorted BIG on top -> SMALL at the bottom.
// size = number of elements in a (list_size), ranks are 0 .. size-1.
// Push the biggest left in a to b each time; the 2 or 3 smallest stay in a
// and get sorted there; then push everything back (smallest of b first).

// how deep (0 = top) the node with this rank is
static int	rank_depth(t_list *stack, int rank)
{
	int	depth;

	depth = 0;
	while (stack->rel_pos != rank)
	{
		stack = stack->down;
		depth++;
	}
	return (depth);
}

// shortest way to bring `rank` to the top of a (len = nodes in a)
static void	bring_to_top(t_list **a, int rank, int len)
{
	int	depth;

	depth = rank_depth(*a, rank);
	if (depth <= len / 2)
		while (depth-- > 0)
			rotateup(a, OP_RA);
	else
		while (depth++ < len)
			rotatedown(a, OP_RRA);
}

// 2 nodes: big on top
static void	sort2(t_list **a)
{
	if ((*a)->rel_pos < (*a)->down->rel_pos)
		swap(a, OP_SA);
}

// 3 nodes: big on top, at most 2 moves
// f s t = top, second, third
static void	sort3(t_list **a)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->rel_pos;
	s = (*a)->down->rel_pos;
	t = (*a)->down->down->rel_pos;
	if (f > s && s > t)
		return ;
	if (t > f && t > s)
	{
		if (s > f)
			swap(a, OP_SA);
		rotatedown(a, OP_RRA);
	}
	else if (s > f && s > t && t > f)
		rotateup(a, OP_RA);
	else if (s > f && s > t)
		swap(a, OP_SA);
	else
	{
		rotatedown(a, OP_RRA);
		swap(a, OP_SA);
	}
}

void	selectionsort(t_list **a, t_list **b, int size)
{
	int	left;

	if (!a || !*a || size < 2 || disorder(*a) == 0)
		return ;
	left = size;
	while (left > 3)
	{
		bring_to_top(a, left - 1, left);
		push(a, b, OP_PB);
		left--;
	}
	if (left == 3)
		sort3(a);
	else
		sort2(a);
	while (*b)
		push(b, a, OP_PA);
}
