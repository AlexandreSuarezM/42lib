/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:35:59 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/24 18:54:40 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>


typedef struct s_list
{
	int				content;
	int				rel_pos;     
	struct s_list	*up;
	struct s_list	*down;
}	t_list;

/* utils/ */
int				ft_atoi(const char *nptr, t_list **lst, char **args);
int				ft_isdigit(char a);
void			ft_lstadd_top(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, char **args);
t_list			*popfirst(t_list **lst);
t_list			*ft_lstnew(int num);
unsigned int	ft_lstsize(t_list *lst);
char			**ft_split(char const *s, char c);
int				ft_strcmp(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
double			disorder(t_list *lst);
void			push(t_list **from, t_list **to);
void			rotatedown(t_list **lst);
void			rotateup(t_list **lst);
void			swap(t_list **lst);
void			chunking(void);
void			Radix(t_list **a, t_list **b, int size);
void			selectionsort(t_list **a, t_list **b, int size);
void			showlist(t_list *a);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_printf(const char *str, ...);

#endif
