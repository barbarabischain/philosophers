/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:39:59 by babischa          #+#    #+#             */
/*   Updated: 2025/01/06 14:07:52 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	one_philo(t_table	*table)
{
	//precisa fazer a thread e o tempo direitinho
	printf("%ld has taken a fork\n", table->nbr_of_philo);
	printf("1 died\n");
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
	table->time_to_die = ft_atol(argv[2]) * 1000;
	table->time_to_eat = ft_atol(argv[3]) * 1000;
	table->time_to_sleep = ft_atol(argv[4]) * 1000;
	if (argv[5])
		table->number_of_meals = ft_atol(argv[5]);
	else
		table->number_of_meals = -1;
}

void	*hello_philosopher(void	*arg)
{
	t_philo			*philo;

	philo = (t_philo*) arg;
	pthread_mutex_lock(&philo->table->mutex_printf);
	printf("hello philosopher %d\n", philo->id);
	pthread_mutex_unlock(&philo->table->mutex_printf);
	return (NULL);
}

void	philosophers_birth(t_table	*table)
{
	int				i;

	i = 0;
	pthread_mutex_init(&table->mutex_printf, NULL);
	table->philos = malloc(sizeof(t_philo) * table->nbr_of_philo);
	while (i < table->nbr_of_philo)
	{
		table->philos[i].id = i;
		table->philos[i].table = table;
		pthread_create(&table->philos[i].thread_id, NULL, &routine, &table->philos[i]);
		//usleep(2000);
		i++;
	}
	i = 0;
	while ( i < table->nbr_of_philo)
	{
		pthread_join(table->philos[i].thread_id, NULL);
		i++;
	}
	pthread_mutex_destroy(&table->mutex_printf);
}

int main(int argc, char **argv)
{
	t_table	table;

	if (!input_checker(argc, argv))
		return (1);
	receive_input(&table, argv);
	philosophers_birth(&table);
	// if (table.nbr_of_philo == 1)
	// 	one_philo(&table);
	return (0);
}
