/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:20:27 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/19 21:28:10 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	algo_decision(char **argv)
{
	else if (argv[0] == "--complex" || argv[1] == "--complex")
		// call complex 
	else if (argv[0] == "--medium" || argv[1] == "--medium")
	 // meidum
	else if (argv[0] == "--simple" || argv[1] == "--simple")
	// simple
	else if (argv[0] == "--adaptive" || argv[1] == "--adaptive")
	else 
	{
		return;
		write(2, "Error\n", 6);
	}
	if (argv[0] == "--bench" || argv[1] == "--bench")
		// call bench
}

int	main(int argc, char **argv)
{
	int	list_size;
	t_list	*new;
	t_list	*alst;
	t_list	*aux;
	t_list	*blst;

	if(argc < 2)
		write(2, "Error\n", 6);
	if(argc < 2)
		return (1);
	list_size = 2; 
	alst = NULL;
	blst = NULL;

// create list 
	// check dupes and rel vas 
	//calculo del rel pos como vamos a loopear por cada elemento de la lista los anteriores add el poco eficiente check
	while(list_size - 2 > 0)
	{
		aux = new->down; 
		while (aux != new)
		{
			if (aux->content == new->content)
			{
				write(2,"Error\n",6);
				return (1);
			}
				if (aux->content < new->content) 
					(new->rel_pos)++;
			aux = aux->down;
		}
		new = new->down;
		list_size--;
	}
	//recover full roation
	new = new->down;

	if (ft_strcmp(argv[1],"--complex") == 0)
		Radix(&alst,&blst, argc - 2);
	//if (ft_strcmp(argv[1],"--simple") == 0)
	//write(1, "Selec\n", 6 );
	//	selectionsort(&alst, &blst, argc - 2);
	//if (argv[1] == "medium")
	//Chunk-based sorting — O(n√n).
	
	//if (argv[1] == "adaptive")
	// adaptive
	//if (argv[1] == "checkers")
	//else
	//	return (0);

	showlist(alst);
	
	ft_lstclear(&alst);
	return (0);
}


//  funcion qu eme tome los argumentos
//  --bench  "1  3   6 " 12     "" 




// parsing from data to model

// gets argv

void init_list(char **argv)
{
	size_t	i;
	char **args;
	size_t	j;

	i = 1;
	while (argv[i])
	{ 
		// args toma los argumentos de cada flag on each args we get it  
		// DOES split args reset ?? if not do it
		args = ft_split(argv[i]);
		j = 0;
		while (args[j])
		{
			skypflag(&i, args[j]); // skip nons and chec the static might be wrong
			ft_lstmew(ft_atoi(args[j]));
			ft_lstadd_top(alst); // direction o alst 
			i++;
		}
		i++;
	}
}

// detects flag if flag is read memory if flag and skpy the pointer
// elongate the if compares the incoming arg 
static void skypflag(int *i, char *arg)
{
	static complex;
	static bench;

	if (ft_strcmp(arg, "--complex") || ft_strcmp(arg, "--medium"))
	{
		complex++;
		*i = *i++;
	}
	if (ft_strcmp(arg, "--simple") || ft_strcmp(arg, "--adaptive"))
	{
		complex++;
		*i = *i++;
	}
	if (ft_strcmp(arg, "--bench"))
	{
		complex++;
		*i = *i++;
	}
	if (complex > 1 || bench > 1)
	{
		ft_lstclear(); // free de los que tenga 
		write(2, "Error\n", 6);
		exit (0);
	}
}

// checks for dupes on the list
// to iterate the list 
// aqui ay tengo el alist creado
static void check_dupes(t_list **alst)
{
	t_list	aux;
	t_list	aux2;

	aux = alst;
	while (aux->down != alst)
	{
		aux2 = aux->down;
		while (aux2 != aux)
		{
			if (aux->content == aux2->content)
				{
					// free & exit & write;
				}
			if (aux->content > aux2->content)
				(*aux)->rel_pos++;
			aux2 = aux2->down;
		}
		aux = aux->down;
	}
}