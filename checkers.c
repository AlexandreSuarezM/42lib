/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 14:00:00 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/26 21:04:11 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "get_next_line.h"

// for checkers use the OP SILENT -1 'not printing option'
static int	do_swap_push(char *op, t_list **a, t_list **b)
{
	if (ft_strcmp(op, "sa\n") == 0)
		swap(a, OP_SILENT);
	else if (ft_strcmp(op, "sb\n") == 0)
		swap(b, OP_SILENT);
	else if (ft_strcmp(op, "ss\n") == 0)
	{
		swap(a, OP_SILENT);
		swap(b, OP_SILENT);
	}
	else if (ft_strcmp(op, "pa\n") == 0)
		push(b, a, OP_SILENT);
	else if (ft_strcmp(op, "pb\n") == 0)
		push(a, b, OP_SILENT);
	else
		return (0);
	return (1);
}

// ra rb rr rra rrb rrr, returns 0 if the line is none of them
static int	do_rotate(char *op, t_list **a, t_list **b)
{
	if (ft_strcmp(op, "ra\n") == 0 || ft_strcmp(op, "rr\n") == 0)
		rotateup(a, OP_SILENT);
	if (ft_strcmp(op, "rb\n") == 0 || ft_strcmp(op, "rr\n") == 0)
		rotateup(b, OP_SILENT);
	if (ft_strcmp(op, "rra\n") == 0 || ft_strcmp(op, "rrr\n") == 0)
		rotatedown(a, OP_SILENT);
	if (ft_strcmp(op, "rrb\n") == 0 || ft_strcmp(op, "rrr\n") == 0)
		rotatedown(b, OP_SILENT);
	return (ft_strcmp(op, "ra\n") == 0 || ft_strcmp(op, "rb\n") == 0
		|| ft_strcmp(op, "rr\n") == 0 || ft_strcmp(op, "rra\n") == 0
		|| ft_strcmp(op, "rrb\n") == 0 || ft_strcmp(op, "rrr\n") == 0);
}

// unknown operation: Error on stderr, free and leave
static void	bad_op(char *line, t_list **a, t_list **b)
{
	free(line);
	ft_lstclear(a, NULL);
	ft_lstclear(b, NULL);
	write(2, "Error\n", 6);
	exit(1);
}
// probably cant call this main go to checkers
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*line;
	int		size;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	size = 0;
	init_list(argv, &a, &size);
	if (!a)
		return (0);
	check_dupes(&a, size);
	line = get_next_line(0);
	while (line)
	{
		if (!do_swap_push(line, &a, &b) && !do_rotate(line, &a, &b))
			bad_op(line, &a, &b);
		free(line);
		line = get_next_line(0);
	}
	if (!b && disorder(a) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
	return (0);
}
