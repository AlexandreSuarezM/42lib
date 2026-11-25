/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 13:00:00 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/25 21:38:28 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// static variable so it keeps adding the value could also be a ** 
int	*op_counter(void)
{
	static int	counts[OP_COUNT];

	return (counts);
}

// list of the ops in names 
char	*op_name(int op)
{
	static char	*names[OP_COUNT] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	if (op < 0 || op >= OP_COUNT)
		return ("");
	return (names[op]);
}

// Prints the op but silent means not but the more i think we always prnt it check subject
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
