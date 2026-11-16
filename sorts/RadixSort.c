/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadixSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 16:44:08 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/16 20:16:39 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
// convert rel _ pos to binary
// loop the list refeed to the byte 1 up to max then send back 
// void recober the n byte of the rel pos in bynary 
// num get feed by rel_val
//int binary(int num, int bit)
//{
//    return ((num >> bit) & 1);
//}
// 2nd while no need to num != 0 reason num is never 0 because we pop on bytes
static int	binary(int num, int byte)
{
	int	aux;
	int	count;

	aux = num;
	count = 0;
	while (aux != 0)
	{
		count ++;
		aux /= 2;
	}
	byte = count - byte;
	if (byte < 1 || byte > count)
    	return (0);
	while(num != 0 && byte != 0)
	{
		byte --;
		num /= 2;
	}
	return (num%2);
}
// size is the amount range of coordinated compresion 
// Does radix sort with list a & b
// rotate while stack len 
// stack len 0 
// size is the argc elements
// if its 0 no elements 
// stakc len gives szie of a 
// we rotate or push each element
void	Radix(t_list **a, t_list **b, int size)
{
	int	byte;
	int	stack_len;
	write(1,"Radix\n",6);
	stack_len = 0;

	byte = 0;


	if(size < 1)
		return;
	while(size != 0)
	{
	
		stack_len = ft_lstsize(*a);
		while (stack_len > 0)
		{
			stack_len --;
				printf("size \t%d \n stack  len %d\n",size, stack_len);
			if(binary((*a)->rel_pos, byte))
			{
				write(1,"rotate\n", 8);
				rotateup(a);
			}
			else
			{	
				write(1,"rotate\n", 8);
				push(a, b);
			}
		
			}
		size /= 2;
		printf("%d\n",size);
		byte ++;
		while(*b)
		{
			write(1, "here", 5 );
			push(b, a);
		}
		write(1, "here", 5 );
	}
}

