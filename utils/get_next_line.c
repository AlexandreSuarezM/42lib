/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 14:00:00 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/25 14:00:00 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// Your plan from arch/get_next_line.c, finished:
// stash (static) keeps what was read after the last '\n'.
// read BUFFER_SIZE bytes and join them to stash until stash has a '\n'
// or the file ends, then cut the line out and keep the rest.

static int	has_newline(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

// stash + buf in a new string, frees the old stash
static char	*join(char *stash, char *buf)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	if (stash)
		i = ft_strlen(stash);
	res = malloc(i + ft_strlen(buf) + 1);
	if (!res)
		return (free(stash), NULL);
	i = 0;
	while (stash && stash[i])
	{
		res[i] = stash[i];
		i++;
	}
	j = 0;
	while (buf[j])
		res[i++] = buf[j++];
	res[i] = '\0';
	free(stash);
	return (res);
}

// length of the first line, '\n' included
static size_t	line_len(char *stash)
{
	size_t	len;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	return (len);
}

// what is left after the first line, frees the old stash
static char	*extract_rest(char *stash)
{
	char	*rest;
	size_t	len;

	if (!stash)
		return (NULL);
	len = line_len(stash);
	if (!stash[len])
		return (free(stash), NULL);
	rest = ft_substr(stash, len, ft_strlen(stash) - len);
	free(stash);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	n = 1;
	while (!has_newline(stash) && n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
			return (free(buf), free(stash), stash = NULL, NULL);
		buf[n] = '\0';
		stash = join(stash, buf);
	}
	free(buf);
	line = NULL;
	if (stash && *stash)
		line = ft_substr(stash, 0, line_len(stash));
	stash = extract_rest(stash);
	return (line);
}
