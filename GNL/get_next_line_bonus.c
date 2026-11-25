/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:47:36 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/29 22:13:48 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// end of doc guard
// documnet can end without a \n
// and it can end ether  with stac
// or with a clean multiple of BUFFER_SIZE
// stack 
// in such case we return the line reminder and free
static char	*eodguard(char **stack)
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

// split of the originial gnl
// i spli the buffer allocation 
// buffer is reserved with calloc
// to avoid any residual mem
// malloc devuelve el adress donde se reserva la memmora por lo que es *ptr
// &ptr es donde esta esa adress guardada
// ptr es el adress de malloc
// *ptr donde esa el primer byte
// por lo que pasar *stack ya nos deja modificar la memoria de stack con free
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
			buffer_len = 0;
	}
	free(buffer);
	return (stack);
}

char	*get_next_line(int fd)
{
	static char	*stack[sizeof(int) * 43];
	char		*line;

	if (fd < 0 || fd >= 43 || BUFFER_SIZE < 1)
		return (NULL);
	stack[fd] = fill_stack(fd, stack[fd]);
	if (stack[fd] == NULL)
		return (NULL);
	if (check(stack[fd]))
		return (eodguard(&stack[fd]));
	line = stackproces(stack[fd]);
	if (line == NULL)
	{
		free(stack[fd]);
		stack[fd] = NULL;
	}
	return (line);
}
