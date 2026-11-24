/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadixSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 16:44:08 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/19 21:25:13 by asuarez          ###   ########.fr       */
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
	// want least significative byte 
	// because each division returns the least significative one 
	// 21 in binari
	// 21 = 10 * 2 res 1 10 = 2*5 0 5 / 2   1   1   1110 in binary that is num %  2   or num / 2    %  2    etc 
	// first iteration is bite 0 and we go up to 1 before num is 0
	if (byte < 0)
		write(1, "negative numeber Error", ft_strlen("negative numeber Error"));
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
// size is argc -2 or -3 since --bench name ad --type 
// size is the value on max bites the argc thetotal number
void Radix(t_list **a, t_list **b, int size)
{
    int byte;
    int stack_len;
    int max_bits;

	if (disorder(t_list *a))
		return;
	stack_len = size;
    max_bits = 0;
    while (stack_len != 0)    
    {
        stack_len /= 2;
        max_bits++;
    }
    byte = 0;
    while (byte < max_bits)
    {
		stack_len = size;
        while (stack_len > 0)
        {
            if (binary((*a)->rel_pos, byte))
                 push(a, b);
            else
        		rotateup(a);
            stack_len--;
        }
        while (*b)
            push(b, a);
        byte++;
    }
}