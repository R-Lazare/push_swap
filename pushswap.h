/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:34:00 by rluiz             #+#    #+#             */
/*   Updated: 2023/09/18 19:24:38 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <limits.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_piles
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	*sorted;
}		t_piles;

t_piles	*parse_piles(t_arena *arena, char **str, int num_of_str);
void	swap_top_elements(int *arr, int size);
void	sa(t_piles *piles);
void	sb(t_piles *piles);
void	ss(t_piles *piles);
void	print_piles(t_piles *piles);
void	pa(t_piles *piles);
void	pb(t_piles *piles);
void	rotate(int *arr, int size);
void	ra(t_piles *piles);
void	rb(t_piles *piles);
void	rr(t_piles *piles);
void	reverse_rotate(int *arr, int size);
void	rra(t_piles *piles);
void	rrb(t_piles *piles);
void	rrr(t_piles *piles);
void	get_sorted(t_arena *arena, t_piles *piles);
void	partition_by_quartiles_a(t_piles *piles);
void	sort_partition(t_piles *piles);
void	find_and_push_max_to_a(t_piles *piles);
t_piles	*copy_piles(t_arena *arena, t_piles *piles);
void	partition_by_quartiles(t_arena *arena, t_piles *piles);
int		is_sorted(t_piles *piles);
int		list_to_positive(t_piles *piles);
int		check_for_duplicates(t_arena *arena, t_piles *piles);
void	safe_exit_error(t_arena *arena);
void	safe_exit_(t_arena *arena);
int		is_full_digit(char *str);

#endif