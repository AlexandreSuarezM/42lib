/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadixSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 16:44:08 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/10 16:23:02 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// convert rel _ pos to binary
// loop the list refeed to the byte 1 up to max then send back 
// void recober the n byte of the rel pos in bynary 
// num get feed by rel_val
//int binary(int num, int bit)
//{
//    return ((num >> bit) & 1);
//}
// 2nd while no need to num != 0 
int	binary(int num, int byte)
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

void	Radix(t_list **a, t_list **b)
{
	int	byte;
	int maxbyte;
	int	aux;
	
	aux = argc - 2;
	maxbyte = 0 ;
	while (aux != 0)
	{
		aux /=2;
		maxbyte ++;
	}
	byte = 0;
	while(byte < maxbyte)
	{ 
			if(binary(lst->rel_val, byte))
				rotate(**a);
			else
				push(**b);
			while(b)
			{
				pushb(*->)
			}
		byte ++;
	}
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



