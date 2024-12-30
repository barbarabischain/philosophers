/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:39:59 by babischa          #+#    #+#             */
/*   Updated: 2024/12/30 17:44:31 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	is_digit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

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
			write(2, "invalid input: expected a number\n", 34);
			return (0);
		}
		i++;
	}
	return (1);
}

void	receive_input(t_table *table, char **argv)
{
	table->nbr_of_philo = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		table->number_of_meals = ft_atol(argv[5]);
	else
		table->number_of_meals = -1;

}

int main(int argc, char **argv)
{
	t_table	table;

	if (!input_checker(argc, argv))
		return (1);
	receive_input(&table, argv);
	return (0);
}
