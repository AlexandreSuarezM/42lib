/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadixSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 16:44:08 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/08 17:26:05 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// convert rel _ pos to binary
// loop the list refeed to the byte 1 up to max then send back 

// void recober the n byte of the rel pos in bynary 
// num get feed by rel_val
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
    	return (-1);
	while(num != 0 && byte != 0)
	{
		byte --;
		num /= 2;
	}
	return (num%2);
}
// alter ** but move *b
//  no need to move b its gets oushed perma
void	Radix(t_list **lst)
{
	int	byte;
	int maxbyte;
	int	aux;
	
	aux = argc - 1;
	maxbyte = 0 ;
	byte = 0;// bytes cannot check for disorder have to check via max bites from argv 
	while (aux != 0)
	{
		aux /=2;
		maxbyte ++;
	}
	while(byte < (argc - 1) )
	{ 
			if(binary(lst->rel_val,byte))
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



