/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selectionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:59:34 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/10 16:22:54 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// find the shortest path to the max value of the stack parse size has argc -2 
int	searchmax(t_list *stack_a, int size)
{
	t_list	*aux;
	int		r;
	
	r = 0;
	aux = stack_a;
	while (r < (size + 1) / 2)
	{
		if (stack_a->rel_pos == size)
			return (r);
		stack_a = stack_a->down;
		r ++;
	}
	return (-r);
}

// parse size as argc - 2  
int	rotatemin(t_list **a, t_list **b, int size)
{
	int		count;

	count = 0;
	while ((*a)->down->down->down)
	{
		if(searchmax(*a, size - count) == 0)
			push(a, b);
		if(searchmax(*a, size - count) < 0)
		{
			while ((*a)->rel_pos != (size - count))
				rotate(a);
			push(a,b);
		}
		else
		{
			while((*a)->rel_pos != (size - count))
				rotatedown(a);
			push(a,b);
		}
		count ++;
	}
	while (*b)
	{
		push(b,a);
	}
}

// max mid min 
// if min on top or bot  roptate
// easy 25 lines fix but eww
void	sort3(**a)
{	
	if(disorder(a) == 0)
		break ;
	if(disorder(a) == 2 )
	{
		if((*a)->rel_val == 0)
		{
			swap(a);
			rotatedown(a);
		}
		else
		{
			swap(a);
			rotatedown(a);
		}
		break;
	}
	if((*a)->rel_pos == 2)
	{
		if((*a)->down->rel_pos == 3)
			swap(a);
		else
			rotatedown(a);
		break;
	}
	roptate(a);
}