/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:20:27 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/23 19:16:47 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//flag snifer detects the flags counts the flags 
//because remembering the flag and checking it is the same
// we keep no track of were the flah was found

// redirects to the desired algoritm 
// this should loop the args and redirect to the desired algortims
// looping the arg

// once the program is well set look the 
//static void	algo_decision(char **argv)
//{
//	while ()
//	else if (argv[i] == "--complex" )
//	// call complex 
//	else if (argv[i] == "--medium" )
//	// meidum
//	else if (argv[i] == "--simple" )
//	// simple
//	else if (argv[i] == "--adaptive")
//	else 
//	{
//		return;
//		write(2, "Error\n", 6);
//	}
//	if (argv[0] == "--bench" || argv[1] == "--bench")
//		// call bench
//}
// take the input
// 

// if no parameters the prompt must be returned as it comes 

//  funcion qu eme tome los argumentos
//  --bench  "1  3   6 " 12     "" 

// checks for known flags returns 1-1 for goo ones 
static int skypflag(char *arg)
{
	if (ft_strcmp(arg, "--complex") == 0)
		return (1);
	if (ft_strcmp(arg, "--simple") == 0)
		return (1);
	if (ft_strcmp(arg, "--bench") == 0)
		return (-1);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (1);
	if(ft_strcmp(arg, "--medium") == 0)
		return (1);
	return (0);
}


// frees every word from ft_split and then the array itself
static void	free_split(char **args)
{
	size_t	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

//
static void	init_list(char **argv, t_list **alst, int *size)
{
	size_t	i;
	char 	**args;
	size_t	j;
	t_list	*node;

	i = 1;
	while (argv[i])
	{
		args = ft_split(argv[i], ' ');
		j = 0;
		while (args && args[j])
		{
			if(skypflag(args[j]))
				j++;
			else
			{
				node = ft_lstnew(ft_atoi(args[j], alst, args));
				ft_lstadd_top(alst, node);
				j++;
				(*size)++;
			}
		}
		free_split(args);
		i++;
	}

}




// takes argv
// counts total flags 
//  exits if too many 
// program can run with no flags 
static	void	flagcount(char **argv)
{
	int flag;
	int flag2;
	int	i;

	i = 0;
	flag = 0;
	flag2 = 0;
	while (argv[i])
	{
		if(skypflag(argv[i]) == 1)
			flag++;
		if(skypflag(argv[i]) == -1)
			flag2++;
		i++;
	}
	if (flag > 1 || flag2 > 1)
		exit (1);
}

// checks for dupes on the list
// to iterate the list 
// alist rel poss count 
// outer loop: visit each of the size nodes once (aux)
// inner loop: compare aux with the other size - 1 nodes (aux2)
static void check_dupes(t_list **alst, int size)
{
	t_list	*aux;
	t_list	*aux2;
	int		i;
	int		j;

	if(!*alst)
		exit(0);
	aux = *alst;
	i = 0;
	while (i < size)
	{
		aux2 = aux->down;
		j = 0;
		while (j < size - 1)
		{
			if (aux->content == aux2->content)
				{
					write(2, "Error\n", 6);
					ft_lstclear(alst, NULL);
					exit(1);
				}
			if (aux->content > aux2->content)
				aux->rel_pos++;
			aux2 = aux2->down;
			j++;
		}
		aux = aux->down;
		i++;
	}
}

// check that the arguments needed are well established
//void    check_args(int argc, char **argv)
//{
//    int i;
//    int pass;
//
//    i = 1;
//	pass = 0;
//    while (i < argc)
//    {
//        if (!ft_strcmp(argv[i], "--simple")
//			|| !ft_strcmp(argv[i], "--complex")
//            || !ft_strcmp(argv[i], "--mediu")
//            || !ft_strcmp(argv[i], "--adaptive"))
//        else if (!ft_strcmp(argv[i], "--bench"))
//            bench = -bench;
//        i++;
//    }
//}

// no numbers to sort no error give back

int	main(int argc, char **argv)
{
	int	list_size;
	t_list	*alst;
	t_list	*blst; // blist summon and clear on each algo maybe

	if(argc < 2)
		return (1);
	list_size = 0; 
	alst = NULL;
	blst = NULL;

	// check flag count
	flagcount(argv);
	// creates a lsit 
	init_list(argv, &alst, &list_size);
	if(!alst)
		exit(1);
	check_dupes(&alst, list_size);

	
	Radix(&alst,&blst, list_size);
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

	//showlist(alst);

	
	ft_lstclear(&alst, NULL);
	return (0);
}
