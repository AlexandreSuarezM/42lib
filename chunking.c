/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:22:06 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/26 21:00:38 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// chunkgin 
// make chunck sizes
// soreach number and chunk again
// sqrt(n) aproximation
static int	ft_isqrt(int n)
{
	int	r;

	r = 0;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

// returns how deep (0 = top) the node with that rank is in the stack
// while this is counted on one of the pusswap loops i would need to parse and ajust the inted 
// maybe remove this one and add indexes
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

// phase 1: empty a into b chunk by chunk
static void	push_chunks(t_list **a, t_list **b, int size, int chunk)
{
	int	limit;

	limit = size - 1;
	while (*a)
	{
		if ((*a)->rel_pos >= limit)
		{
			push(a, b, OP_PB);
			if ((*b)->down != *b)
				rotateup(b, OP_RB);
			limit--;
		}
		else if ((*a)->rel_pos >= limit - chunk)
		{
			push(a, b, OP_PB);
			limit--;
		}
		else
			rotateup(a, OP_RA);
	}
}

// phase 2: bring back ranks 0, 1, 2 ... size-1 using the shortest rotation
static void	pull_back(t_list **a, t_list **b, int size)
{
	int	rank;
	int	depth;
	int	left;

	rank = 0;
	left = size;
	while (rank < size)
	{
		depth = rank_depth(*b, rank);
		if (depth <= left / 2)
			while (depth-- > 0)
				rotateup(b, OP_RB);
		else
			while (depth++ < left)
				rotatedown(b, OP_RRB);
		push(b, a, OP_PA);
		rank++;
		left--;
	}
}

void	chunking(t_list **a, t_list **b, int size)
{
	int	chunk;

	if (!a || !*a || size < 2 || disorder(*a) == 0)
		return ;
	chunk = ft_isqrt(size) * 3 / 2;
	if (chunk < 1)
		chunk = 1;
	push_chunks(a, b, size, chunk);
	pull_back(a, b, size);
}
