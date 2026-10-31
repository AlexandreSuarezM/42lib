

//
void	*del(void *a)
{
	unsigned char	*b;
	b = (unsigned char *)a;
	while(b)
	{
		b = 0;
		b ++;
	}
	return (b);
}


int main(int argc, char**argv)
{
	if(argc < 1)
		return 0;
	t_list *lst;
	int *values;

	while(i < argc)
		values[i] = atoi(argv[i]);

	i = 0;
	while(i < argc)
	{
		i = j;
		while (j < argv)
		{
			j++;
			if (argv[i] == argv[j])
				return (NULL);
		}
		i++;
	}

	int i = 0;
	while (i < argc)
	{
		ft_lstadd_front(ft_lstnew(atoi(argv[i])));
		i ++;
	}
	// definition algor(int **)
	// call  algor(&stack)
	ft_lstsize(t_list *lst);
	ft_lstclear(t_list **lst, void (*del)(void*));
	// free all nodes in stack finished.
	// because there are no repetitions we dont get  stucka


	return 0;
}

// operations have del good
// 

