/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:17:20 by gpatrici          #+#    #+#             */
/*   Updated: 2025/12/16 14:57:01 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_parse_data
{
	int				*values;
	int				size;
}					t_parse_data;

typedef struct s_snode
{
	int				value;
	int				index;
	struct s_snode	*prev;
	struct s_snode	*next;
}					t_snode;

typedef struct s_stack
{
	t_snode			*head;
	t_snode			*tail;
	int				size;
}					t_stack;

int					error(int err_code, int should_exit);

// Parsing functions
t_parse_data		*parse_args(int argc, char **argv);
t_parse_data		*parse_single_arg(char *arg);
t_parse_data		*parse_multi_args(int argc, char **argv);
int					*convert_split_to_values(char **split, int size);
int					is_valid_number(char *str);
int					has_duplicates(int *values, int size);
void				free_parse_data(t_parse_data *data);
void				free_split(char **split);
int					get_split_size(char **split);

// Stack initialization
t_stack				*init_stack(void);
t_stack				*init_stack_a(int *values, int size);

// Node operations
t_snode				*create_node(int value, int index);
void				free_node(t_snode *node);

// Stack operations
void				push_front(t_stack *stack, t_snode *node);
void				push_back(t_stack *stack, t_snode *node);
t_snode				*pop_front(t_stack *stack);
t_snode				*pop_back(t_stack *stack);

// Stack utilities
void				free_stack(t_stack *stack);
int					is_empty(t_stack *stack);
void				print_stack(t_stack *stack, char stack_name);
void				assign_indices(t_stack *stack);

#endif
