// probably need to put exits on the function ... but idk how it goes 
char	*skip_spaces(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}
int	get_sign(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}
int	is_number(char *str)
{
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
int	number_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] >= '0' && str[len] <= '9')
		len++;
	return (len);
}
int	compare_positive(char *a, char *b)
{
	int	len_a;
	int	len_b;

	len_a = number_len(a);
	len_b = number_len(b);
	if (len_a > len_b)
		return (1);
	if (len_a < len_b)
		return (-1);
	return (ft_strcmp(a, b));
}
int	compare_numbers(char *a, char *b)
{
	if (*a == '-' && *b != '-')
		return (-1);
	if (*a != '-' && *b == '-')
		return (1);
	if (*a == '-' && *b == '-')
		return (-compare_positive(a + 1, b + 1));
	return (compare_positive(a, b));
}
int	compare(char *a, char *b)
{
	int	sign_a;
	int	sign_b;

	a = skip_spaces(a);
	b = skip_spaces(b);
	sign_a = get_sign(&a);
	sign_b = get_sign(&b);
	if (!is_number(a) || !is_number(b))
		return (0); // Invalid input
	if (sign_a != sign_b)
		return (sign_a - sign_b);
	if (sign_a == -1)
		return (-compare_positive(a, b));
	return (compare_positive(a, b));
}