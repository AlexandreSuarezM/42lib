/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:47:36 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/28 18:29:09 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// If the document does not end with \n
//  the last line thatis not ended has to show
// this goes in the if 
// parse ** stack to alter *stack
// this part ensure the case when
//  no \n is found  before eod is reachead
static	char	*eodguard(char **stack)
{
	char	*line;

	if (*stack == NULL || *stack[0] == '\0')
	{
		free(*stack);
		*stack = NULL;
		return (NULL);
	}
	line = *stack;
	*stack = NULL;
	return (line);
}
// while enters iif stack  is  NULL  or no \n
// read the buffer
// if fd has an error free satck if not NULL and end
// if eod is reached and the while is still in 
//  baiscally fd not endinwith \n 
// free the stack and return  the correspoendin  part if so

static char	*fill_stack(int fd, char *stack)
{
	char	*buffer;
	int		buffer_len;

	buffer = ft_calloc(BUFFER_SIZE, 1, &stack);
	if (!buffer)
		return (NULL);
	buffer_len = 1;
	while (buffer_len > 0 && check(stack))
	{
		buffer_len = read(fd, buffer, BUFFER_SIZE);
		if (buffer_len < 0)
		{
			free(stack);
			stack = NULL;
		}
		if (buffer_len > 0)
			stack = ft_concat(stack, buffer, buffer_len);
		if (stack == NULL)
			break ;
	}
	free(buffer);
	return (stack);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	if (fd < 0 || fd >= 43 || BUFFER_SIZE < 1)
		return (NULL);
	stack = fill_stack(fd, stack);
	if (stack == NULL)
		return (NULL);
	if (check(stack))
		return (eodguard(&stack));
	line = stackproces(stack);
	if (line == NULL)
	{
		free(stack);
		stack = NULL;
	}
	return (line);
}
