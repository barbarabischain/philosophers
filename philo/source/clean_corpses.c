/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_corpses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:53:49 by babischa          #+#    #+#             */
/*   Updated: 2025/01/13 14:03:11 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	clean_corpses(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philo)
		pthread_join(table->philos[i++].thread_id, NULL);
	i = 0;
	while (i < table->nbr_of_philo)
	{
		pthread_mutex_destroy(&table->philos[i].mutex_meal);
		pthread_mutex_destroy(&table->forks[i++].fork_mutex);
	}
	pthread_mutex_destroy(&table->mutex_printf);
	pthread_mutex_destroy(&table->mutex_death);
	free(table->forks);
	free(table->philos);
	table->philos = NULL;
}
