/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 13:00:00 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/25 13:00:00 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// --bench: prints the stats on stderr (fd 2) so stdout keeps only the
// operations and a checker can still read them. Example:
// [bench] disorder: 49.93%
// [bench] strategy: Adaptive / O(n√n)
// [bench] total_ops: 2304
// [bench] sa: 0 sb: 0 ss: 0 pa: 500 pb: 500
// [bench] ra: 868 rb: 432 rr: 0 rra: 0 rrb: 0 rrr: 4

static void	put_str(char *s)
{
	write(2, s, ft_strlen(s));
}

static void	put_nbr(long n)
{
	char	c;

	if (n >= 10)
		put_nbr(n / 10);
	c = '0' + n % 10;
	write(2, &c, 1);
}

// disorder 0.4993 -> "49.93%"
static void	put_disorder(double dis)
{
	long	n;

	n = (long)(dis * 10000 + 0.5);
	put_str("[bench] disorder: ");
	put_nbr(n / 100);
	put_str(".");
	if (n % 100 < 10)
		put_str("0");
	put_nbr(n % 100);
	put_str("%\n");
}

// flag = the flag given, used = flag of the sort that really ran
// (they only differ for --adaptive)
static void	put_strategy(char *flag, char *used)
{
	put_str("[bench] strategy: ");
	if (ft_strcmp(flag, "--adaptive") == 0)
		put_str("Adaptive / ");
	else if (ft_strcmp(flag, "--simple") == 0)
		put_str("Simple / ");
	else if (ft_strcmp(flag, "--medium") == 0)
		put_str("Medium / ");
	else
		put_str("Complex / ");
	if (ft_strcmp(used, "--simple") == 0)
		put_str("O(n²)\n");
	else if (ft_strcmp(used, "--medium") == 0)
		put_str("O(n√n)\n");
	else
		put_str("O(n log n)\n");
}

// dis must be measured BEFORE sorting
void	bench(double dis, char *flag, char *used)
{
	int		op;
	long	total;

	put_disorder(dis);
	put_strategy(flag, used);
	total = 0;
	op = 0;
	while (op < OP_COUNT)
		total += op_counter()[op++];
	put_str("[bench] total_ops: ");
	put_nbr(total);
	op = 0;
	while (op < OP_COUNT)
	{
		if (op == OP_SA || op == OP_RA)
			put_str("\n[bench]");
		put_str(" ");
		put_str(op_name(op));
		put_str(": ");
		put_nbr(op_counter()[op++]);
	}
	put_str("\n");
}
