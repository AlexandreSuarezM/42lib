/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:20:27 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/23 16:04:08 by asuarez          ###   ########.fr       */
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
	// calculo del rel pos como vamos a loopear por cada elemento de la lista los anteriores add el poco eficiente check
	// list size -1 name -flag -optional flag.




	
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

	//showlist(alst);
	printf("%d\n",dis)
	
	ft_lstclear(&alst);
	return (0);
}

// if no parameters the prompt must be returned as it comes 

//  funcion qu eme tome los argumentos
//  --bench  "1  3   6 " 12     "" 




// 
static void	init_list(char **argv)
{
	size_t	i;
	char 	**args;
	size_t	j;
	static flag[5];   // the flags are ordered has simple medium complex adaptive bench
	
	i = 1;
	while (argv[i])
	{
		args = ft_split(argv[i]);
		j = 0;
		while (args[j])
		{
			if(skypflag(args[j]))
				j++;
			else
			{
				ft_lstmew(ft_atoi(args[j]));
				ft_lstadd_top(alst); // direction o alst 
				j++;
			}
		}
		i++;
	}
	if(complex == 0)  // if no arguments return the same promp wich is char * separted by space.
	{
		while(argv[i])
			ft_printf("%s' '",argv[i]);
	}
}

// is args a flag
// did we have flags 
// are the flags okey
// 
static int skypflag(char *arg)
{
	if (ft_strcmp(arg, "--complex") || ft_strcmp(arg, "--medium"))
	{
		flag[2]++;
		return (1);
	}
	if (ft_strcmp(arg, "--simple") || ft_strcmp(arg, "--adaptive"))
	{
		flag[0]++;
		return (1);
	}
	if (ft_strcmp(arg, "--bench"))
	{
		flag[4]++;
		return (1);
	}
	if (flag[0] + flag[1] + flag[2] + flag[3] > 1 || flag[5] > 1)
	{
		ft_lstclear(); // free de los que tenga 
		write(2, "Error\n", 6);
		exit (0);
	}
	return (0);
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

// check that the arguments needed are well established
void    check_args(int argc, char **argv)
{
    int i;
    int pass;

    i = 1;
	pass = 0;
    while (i < argc)
    {
        if (!ft_strcmp(argv[i], "--simple")
			|| !ft_strcmp(argv[i], "--complex")
            || !ft_strcmp(argv[i], "--mediu")
            || !ft_strcmp(argv[i], "--adaptive"))
        else if (!ft_strcmp(argv[i], "--bench"))
            bench = -bench;
        i++;
    }
}