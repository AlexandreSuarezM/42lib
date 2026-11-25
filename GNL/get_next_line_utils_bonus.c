/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 22:41:46 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/29 21:56:59 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// check for while condtion to keep buffering 
// as long has no \n is found in the while if no 
// \n is found it can also leave by hitting eod 
int	check(char *str)
{
	int		i;

	if (str == NULL)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// strlen that returns 0 on null 
size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (str != NULL)
	{
		while (str[len])
			len++;
	}
	return (len);
}

// calloc to  get teh buffer 0,s in case full buffer is not reachead.
char	*ft_calloc(size_t amount, size_t tipe, char **stack)
{
	char	*memalloc;
	size_t	i;

	memalloc = malloc(amount * tipe);
	if (memalloc == NULL)
	{
		free(*stack);
		*stack = NULL;
		return (NULL);
	}
	i = 0;
	while (i < amount * tipe)
	{
		memalloc[i] = '\0';
		i++;
	}
	return (memalloc);
}

// concat on the newstack by appending the buffers
char	*ft_concat(char *stack, char *buffer, int buffer_len)
{
	char	*newstack;
	size_t	i;
	int		j;
	size_t	stack_len;

	i = 0;
	stack_len = ft_strlen(stack) + 1;
	newstack = ft_calloc(stack_len + buffer_len, sizeof(char), &stack);
	if (newstack == NULL)
		return (NULL);
	while (i < (stack_len - 1) && stack != NULL)
	{
		newstack[i] = stack[i];
		i++;
	}
	free(stack);
	j = 0;
	while (j < buffer_len)
	{
		newstack[i + j] = buffer[j];
		j++;
	}
	newstack[i + j] = '\0';
	return (newstack);
}

//  get the \n of sack stop if \n or end of stack
//  and fill it with \0 
char	*stackproces(char *stack)
{
	size_t	i;
	size_t	j;
	char	*line;

	if (stack == NULL)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		line[j] = stack[j];
		j++;
	}
	line[j] = '\0';
	j = 0;
	while (stack[i + 1 + j++])
		stack[j - 1] = stack[i + j];
	stack[j - 1] = '\0';
	return (line);
}
