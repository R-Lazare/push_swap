/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:06:11 by rluiz             #+#    #+#             */
/*   Updated: 2023/09/18 19:24:23 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	safe_exit(t_arena *arena)
{
	arena_destroy(arena);
	exit(0);
}

void	safe_exit_error(t_arena *arena)
{
	ft_printf("Error\n");
	arena_destroy(arena);
	exit(0);
}

int is_full_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_arena	*arena;
	t_piles	*piles;

	if (argc < 2)
		return (0);
	arena = arena_init(65536);
	piles = parse_piles(arena, argv, argc - 1);
	if (piles->size_a < 2 || piles->size_a > 5000 || is_sorted(piles))
		safe_exit(arena);
	check_for_duplicates(arena, piles);
	list_to_positive(piles);
	get_sorted(arena, piles);
	///print_piles(&(t_piles){.a = piles->sorted, .size_a = piles->size_a});
	partition_by_quartiles_a(piles);
	find_and_push_max_to_a(piles);
	arena_destroy(arena);
	return (0);
}
