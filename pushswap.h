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

/* operation codes: index in the bench counter, OP_SILENT = no print/count */
# define OP_SILENT		-1
# define OP_SA			0
# define OP_SB			1
# define OP_SS			2
# define OP_PA			3
# define OP_PB			4
# define OP_RA			5
# define OP_RB			6
# define OP_RR			7
# define OP_RRA			8
# define OP_RRB			9
# define OP_RRR			10
# define OP_COUNT		11

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

/* Operations/ */
void			push(t_list **from, t_list **to, int op);
void			rotatedown(t_list **lst, int op);
void			rotateup(t_list **lst, int op);
void			swap(t_list **lst, int op);
void			ss(t_list **a, t_list **b);
void			rr(t_list **a, t_list **b);
void			rrr(t_list **a, t_list **b);
int				*op_counter(void);
char			*op_name(int op);
void			op_log(int op);

/* sorts/ */
void			chunking(t_list **a, t_list **b, int size);
void			Radix(t_list **a, t_list **b, int size);
void			selectionsort(t_list **a, t_list **b, int size);
char			*adaptive(t_list **a, t_list **b, int size);
char			*sort_stack(t_list **a, t_list **b, int size, char *flag);

/* utils/parse.c (shared by push_swap and checker) */
int				skypflag(char *arg);
void			init_list(char **argv, t_list **alst, int *size);
void			check_dupes(t_list **alst, int size);

/* utils/get_next_line.c */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char			*get_next_line(int fd);

/* bench.c */
void			bench(double dis, char *flag, char *used);
void			showlist(t_list *a);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_printf(const char *str, ...);

#endif
