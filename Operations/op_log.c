/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 13:00:00 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/25 13:00:00 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// One counter per operation, indexed with OP_SA ... OP_RRR.
// No globals allowed: the array lives as a static inside this function
// and everyone gets to it through the returned pointer.
int	*op_counter(void)
{
	static int	counts[OP_COUNT];

	return (counts);
}

// name of an operation, without the newline
char	*op_name(int op)
{
	static char	*names[OP_COUNT] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	if (op < 0 || op >= OP_COUNT)
		return ("");
	return (names[op]);
}

// counts the operation and prints it on stdout.
// OP_SILENT (-1) does nothing: used by ss/rr/rrr for their 2 inner moves
// and later by the checker.
void	op_log(int op)
{
	char	*name;

	if (op < 0 || op >= OP_COUNT)
		return ;
	op_counter()[op]++;
	name = op_name(op);
	write(1, name, ft_strlen(name));
	write(1, "\n", 1);
}
