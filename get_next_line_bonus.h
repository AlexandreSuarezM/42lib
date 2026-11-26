/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:01:58 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/29 21:57:31 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		check(char *str);
size_t	ft_strlen(char *str);
char	*ft_calloc(size_t amount, size_t tipe, char **stack);
char	*ft_concat(char *stack, char*buffer, int buffer_len);
char	*stackproces(char *stack);

#endif
