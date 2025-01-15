/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:59:42 by babischa          #+#    #+#             */
/*   Updated: 2025/01/15 15:32:38 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	input_checker(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc > 6 || argc < 5)
	{
		write(2, "invalid input\n", 14);
		return (0);
	}
	while (argv[i])
	{
		if (!is_digit(argv[i]))
		{
			write(2, "invalid input\n", 14);
			return (0);
		}
		i++;
	}
	return (1);
}

int main(int argc, char	**argv)
{
	t_table	table;

	if (!input_checker(argc, argv))
		return (1);
	set_table(&table, argv);
	philosophers_birth(&table);
	while (!find_corpse(&table))
		;
	clean_corpses(&table);
}
