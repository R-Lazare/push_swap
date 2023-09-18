/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:33:13 by rluiz             #+#    #+#             */
/*   Updated: 2023/09/18 19:32:11 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_piles	*parse_piles(t_arena *arena, char **str, int num_of_str)
{
	t_piles	*piles;
	int		i;
	int		j;

	i = 0;
	piles = arena_alloc(arena, sizeof(t_piles));
	piles->a = arena_alloc(arena, sizeof(int) * num_of_str);
	piles->size_a = num_of_str;
	piles->b = arena_alloc(arena, sizeof(int) * num_of_str);
	piles->size_b = 0;
	j = -1;
	while (++j <= num_of_str)
	{
		if (ft_isdigit(str[j][0]) || (str[j][0] == '-' && ft_isdigit(str[j][1])))
			piles->a[i++] = (int)ft_atoi(arena, str[j]);
		if (ft_isalpha(str[j][0]))
			safe_exit_error(arena);
	}
	return (piles);
}

void	print_piles(t_piles *piles)
{
	int	i;

	i = 0;
	while (i < piles->size_a || i < piles->size_b)
	{
		if (i < piles->size_a)
			ft_printf("%d", piles->a[i]);
		else
			ft_printf(" ");
		ft_printf(" | ");
		if (i < piles->size_b)
			ft_printf("%d", piles->b[i]);
		else
			ft_printf(" ");
		ft_printf("\n");
		i++;
	}
}

void	get_sorted(t_arena *arena, t_piles *piles)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	piles->sorted = arena_alloc(arena, sizeof(int) * piles->size_a);
	while (++i < piles->size_a)
		piles->sorted[i] = piles->a[i];
	i = -1;
	while (++i < piles->size_a)
	{
		j = i;
		while (++j < piles->size_a)
		{
			if (piles->sorted[i] > piles->sorted[j])
			{
				tmp = piles->sorted[i];
				piles->sorted[i] = piles->sorted[j];
				piles->sorted[j] = tmp;
			}
		}
	}
}

int	direction_rotate(t_piles *piles, int min)
{
	int	i;
	int	index_r_valid;
	int	index_rr_valid;

	i = -1;
	index_r_valid = -1;
	index_rr_valid = -1;
	while (++i < piles->size_a)
	{
		if (piles->a[i] < min)
		{
			index_r_valid = i;
			break ;
		}
		if (piles->a[piles->size_a - i - 1] < min)
		{
			index_rr_valid = i;
			break ;
		}
	}
	if (index_r_valid != -1)
		return (1);
	return (0);
}

int	check_for_duplicates(t_arena *arena, t_piles *piles)
{
	int	i;
	int	j;

	i = -1;
	while (++i < piles->size_a)
	{
		j = i;
		while (++j < piles->size_a)
		{
			if (piles->a[i] == piles->a[j])
				safe_exit_error(arena);
		}
	}
	return (0);
}
