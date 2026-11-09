/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selectionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:59:34 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/09 17:54:54 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// tengo 1 rotacion ambos sentidos para max om min
// si entre las rotaciones existe una rotacion menos costosa 
// explico 
// insertar un elemento custa rotacione 
// hay que insertar buscando el minimo
// las roptaciones 
// qual es el numbero siguiente que se pueede inserir 
// loop clocwise
// loop counterwise
// loop both 
// loop for max loop for min 
// that is a find element 
// so each element returns a rotation number
// so given (num of stack a) 
// counts how many rotations costs  to b to fit it in 
// and looping elements of a gives mes the cost of getting an element in a 

// so i do the whole check to find the shortest operation every time 

// loooks the cost of finding a in stack a rotate or reverse rotate 0 rotate 1 reverse rotate
// remark that if the list makes it find max in more that int range it has a bug
// count the fastest way to spot max.
void	searchmax(t_list *stack_a)
{
	t_list	*aux;
	int		r;
	
	r = 0;
	aux = stack_a;
	while (stack_a->rel_pos != (argc - 2))
	{
		stack_a = stack_a->down;
		r ++;
	}
	stack_a = aux;
	while (stack_a->rel_pos != (argc - 2))
	{
		stack_a = stack_a->up;
		r --;
	}
	return (r);
}

int	rotatemin(t_list **a, t_list **b)
{
	t_list	*a_aux;
	t_list	*b_aux;
	int		count;

	count = 0;
	a_aux = *a; 

	// *a has to be the last 3 to make 
	while (*a && )
	{
		if(searchmax(*a) = 0)
			pusha;
		if(searchmax(*a) < 0)
			while ()
				rotate
			push
		else()
			while()
				reverse_rotate
			push
	}
	while (*b)
	{
		pushb;
	}
	// shit sorting 0 consideration n^2 scaling 
	// can improve if the loop goes past the half we done once we find one the reverse rotate gets autocalculated .
	// move a move a & b move b  b is sorted 
	// to move b means its always on the side
	// to move a is random
	// to move both kk
	// wtf pure euristic find min and cba
	// Add the sort 3 looking for max its only a permulation 



}