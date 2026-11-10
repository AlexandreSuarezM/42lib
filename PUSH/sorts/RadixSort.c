/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadixSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 16:44:08 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/10 17:17:21 by asuarez          ###   ########.fr       */
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
// 2nd while no need to num != 0 
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
void	Radix(t_list **a, t_list **b, int size)
{
	int	byte;
	
	byte = 0;
	while(size != 0)
	{ 
			if(binary(lst->rel_val, byte))
				rotateup(**a);
			else
				push(**a, **b);
			while(b)
			{
				push(**b, **a);
			}
		size /= 2;
		byte ++;
	}
}



