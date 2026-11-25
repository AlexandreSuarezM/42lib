/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadixSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 16:44:08 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/24 18:58:50 by asuarez          ###   ########.fr       */
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
	if (byte < 0)
		write(1, "negative numeber Error", ft_strlen("negative numeber Error"));
	while(byte != 0)
	{
		byte --;
		num /= 2;
	}
	return (num%2);
}

void Radix(t_list **a, t_list **b, int size)
{
    int byte;
    int stack_len;
    int max_bits;

	if (!disorder(*a))
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
                 push(a, b, OP_PB);
            else
        		rotateup(a, OP_RA);
            stack_len--;
        }
        while (*b)
            push(b, a, OP_PA);
        byte++;
    }
}

//CC = gcc
//CFLAGS = -Wall -Wextra
//
//LDFLAGS = -L.
//LDLIBS = -lmain -lmiddle -lexternal
//
//all: program
//
//program: main.o libmain.a libmiddle.a libexternal.a
//	$(CC) main.o $(LDFLAGS) $(LDLIBS) -o program
//
//main.o: main.c
//	$(CC) $(CFLAGS) -c main.c -o main.o
//
//libmain.a: main_lib.o
//	ar rcs $@ $^
//
//libmiddle.a: middle.o
//	ar rcs $@ $^
//
//libexternal.a: external.o
//	ar rcs $@ $^
//
//clean:
//	rm -f *.o *.a program