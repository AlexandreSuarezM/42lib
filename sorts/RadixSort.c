/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadixSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 16:44:08 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/17 17:52:38 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
// struct return based or code based with ineger void return 
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

	// total de bites de num

	// queremos la posicion 0 1 2 3 si count es 4 tenemos 5 ellementos el byte dice de los 5 elementos tenemos -bytes
	// start yte 0 i go u p if num es small and past byes 0    1 is 1 and if byte is 0 thenn 1 
	// if num =0 cunt 0 its negative  if num byte i  bytes are pased 

	while(byte != 0)
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

void Radix(t_list **a, t_list **b, int size)
{
    int byte;
    int stack_len;
    int max_bits;

    if (size < 1)
        return;

    max_bits = 0;
    while ((size - 1) != 0)
    {
        size /= 2;
        max_bits++;
    }

    byte = 0;
    while (byte < max_bits)
    {
        stack_len = ft_lstsize(*a);

        while (stack_len > 0)
        {
            if (binary((*a)->rel_pos, byte))
                rotateup(a);
            else
                push(a, b);
            stack_len--;
        }

        while (*b)
            push(b, a);

        byte++;
    }
}