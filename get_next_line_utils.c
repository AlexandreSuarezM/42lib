/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 22:41:46 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/28 19:30:47 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	gnl_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (str != NULL)
	{
		while (str[len])
			len++;
	}
	else
	{
		return (0);
	}
	return (len);
}

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

char	*ft_concat(char *stack, char *buffer, int buffer_len)
{
	char	*newstack;
	size_t	i;
	int		j;
	size_t	stack_len;

	i = 0;
	stack_len = gnl_strlen(stack) + 1;
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
