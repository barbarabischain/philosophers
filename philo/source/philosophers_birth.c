/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_birth.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:25:19 by babischa          #+#    #+#             */
/*   Updated: 2025/01/15 17:32:36 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	philosophers_birth(t_table *table)
{
	int	i;

	i = 0;
	table->philos = malloc(sizeof(t_philo) * table->nbr_of_philo);
	memset(table->philos, 0, (sizeof(t_philo) * table->nbr_of_philo));
	while (table->nbr_of_philo > i)
	{
		pthread_mutex_init(&table->philos[i].mutex_lastmeal, NULL);
		table->philos[i].id = i;
		table->philos[i].table = table;
		table->philos[i].left_fork = &table->forks[i];
		if (table->nbr_of_philo > 1)
			table->philos[i].right_fork = &table->forks[(i + 1) \
			% table->nbr_of_philo];
		table->philos[i].last_meal = get_time();
		table->philos[i].start_time = table->philos[i].last_meal;
		if (table->nbr_of_philo == 1)
			pthread_create(&table->philos[i].thread_id, NULL, \
			&one_philo, &table->philos[i]);
		else
			pthread_create(&table->philos[i].thread_id, NULL, \
			&life_cicle, &table->philos[i]);
		i++;
	}
}
