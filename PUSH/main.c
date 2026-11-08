// we handle itns     vs    we map the char numbers to a table .
// lst adjusted for bidirectional loop


#include "libft.h"

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int	i;

	t_list	*new;
	t_list	*alst;
	t_list	*aux;
	t_list	*blst;

	i = 1;
	if(argc < 1)
		return (0);

	while (i < argv)
	{
		// create with the value 
		new = ft_lstnew((argv[i]));
		// add on the top of the stack 
		ft_lstadd_top(&alst, new);
	}

	// stack b gets initialized with a lstadd 
	// sorting 


	new = alst;
	while(new->down)
	{
		aux = new->down;
		while (aux)
		{
			if (aux->value == new->value || isnum(new->value))
				return (1);
			if (bigger(aux->value,new->value) < 0)
				new->rel_pos++;
			aux = aux->down;
		}
		new = new->down;
	}
	if (isnum(aux->value))
		return (1);
	// now we get the index of the max element no need tho its argcv
	//ft_lstsize(alst);
	

	ft_lstclear(&alst);
	return (0);
}
// adjust the argc counts because the --tipe takes on slot

if (argv[1] == "")
// algo
if (argv[1] == "")
// algo
if (argv[1] == "")
// algo:
else



// after the if values are nums and no equal
// if same len return the strcmp wich si the bigger
// else the longest 
// positive first is the bigger cant be 0 discardted on previous while 
int bigger(char  *first, char *second)
{
	if(first[0] == '-' && second[0] != '-')
		return (-1);
	if(first[0] != '-' && second[0] == '-')
		return (1);
	if(first[0] == '-' && second[0] == '-')
	{
		if(ft_strlen(first) == ft_strlen(second))
			return ((int)ft_strcmp(second, first));
		return((int)(ft_strlen(second) - ft_strlen(first)));	
	}	
	
	if(ft_strlen(first) == ft_strlen(second))
		return (ft_strcmp(first, second));
	return(ft_strlen(first) - ft_strlen(second));
}

