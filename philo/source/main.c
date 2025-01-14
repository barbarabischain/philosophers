/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:39:59 by babischa          #+#    #+#             */
/*   Updated: 2025/01/14 13:45:07 by babischa         ###   ########.fr       */
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

void	receive_input(t_table *table, char **argv)
{
	table->nbr_of_philo = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	table->die = 0;
	if (argv[5])
		table->number_of_meals = ft_atol(argv[5]);
	else
		table->number_of_meals = -1;
}

void	philosophers_birth(t_table	*table)
{
	int	i;

	i = 0;
	pthread_mutex_init(&table->mutex_death, NULL);
	pthread_mutex_init(&table->mutex_printf, NULL);
	forge_forks(table);
	table->philos = malloc(sizeof(t_philo) * table->nbr_of_philo);
	memset(table->philos, 0, sizeof(t_philo) * table->nbr_of_philo);
	while (i < table->nbr_of_philo)
	{
		pthread_mutex_init(&table->philos[i].mutex_meal, NULL);
		table->philos[i].id = i;
		table->philos[i].table = table;
		table->philos[i].left_fork = &table->forks[i];
			if (table->nbr_of_philo > 1)
				table->philos[i].right_fork = &table->forks[(i + 1) % table->nbr_of_philo];
		table->philos[i].nbr_of_meals = table->number_of_meals;
		table->philos[i].last_meal = get_time();
		table->philos[i].start_time = table->philos[i].last_meal;
		if (table->nbr_of_philo == 1)
			pthread_create(&table->philos[i].thread_id, NULL, &one_philo, &table->philos[i]);
		else
			pthread_create(&table->philos[i].thread_id, NULL, &life_cicle, &table->philos[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (!input_checker(argc, argv))
		return (1);
	receive_input(&table, argv);
	philosophers_birth(&table);
	search_corpses(&table);
	clean_corpses(&table);
	return (0);
}
