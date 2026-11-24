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
// find the shortest path to the max value of the stack parse size has argc -2 
static	int	searchmax(t_list *stack_a, int size)
{
	int		r;
	
	r = 0;
	while (r < (size + 1) / 2)
	{
		if (stack_a->rel_pos == size)
			return (r);
		stack_a = stack_a->down;
		r ++;
	}
	return (-r);
}

//ewwwww 
static	void	sort3(t_list **a)
{	
	if ((*a)->rel_pos > ((*a)->down->rel_pos))
	{
		if((*a)->rel_pos == 2)
			rotatedown(a);
		if((*a)->down->down->rel_pos == 2 )
		{
			swap(a);
			rotateup(a);
		}
	}
	else
	{
		if((*a)->rel_pos == 2)
			swap(a);
		else if((*a)->down->rel_pos == 2)
		{
			swap(a);
			rotatedown(a);
		}
		else
			rotateup(a);
	}
}
// parse size as argc - 2  
void	selectionsort(t_list **a, t_list **b, int size)
{
	int		count;
write(1,"Selec\n",6);

	if (disorder(*a))
		return;
	count = 0;
	while ((*a)->down->down->down)
	{
		if(searchmax(*a, size - count) == 0)
			push(a, b);
		else if(searchmax(*a, size - count) < 0)
		{
			while ((*a)->rel_pos != (size - count))
				rotateup(a);
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
	sort3(a);
	while (*b)
		push(b,a);
}

void	sort2(t_list ** a)
{
	if ((*a)->down->down == NULL)
	{
  	 if ((*a)->rel_pos > (*a)->down->rel_pos)
  	     swap(a);
  	 return;
	}
//
//
//oid selectionsort(t_list **a, t_list **b, int size)
//
//   int count;
//   int pos;
//
//   if (!*a || !(*a)->down)
//       return;
//   if (disorder(*a) == 0)
//       return;
//   if ((*a)->down->down == *a)
//   {
//       if ((*a)->rel_pos > (*a)->down->rel_pos)
//           swap(a);
//       return;
//   }
//   count = 0;
//   while ((*a)->down->down->down != *a)
//   {
//       pos = searchmax(*a, size - count);
//       if (pos == 0)
//           push(a, b);
//       else if (pos < 0)
//       {
//           while ((*a)->rel_pos != size - count)
//               rotateup(a);
//           push(a, b);
//       }
//       else
//       {
//           while ((*a)->rel_pos != size - count)
//               rotatedown(a);
//           push(a, b);
//       }
//       count++;
//   }
//   sort3(a);
//   while (*b)
//       push(b, a);
//