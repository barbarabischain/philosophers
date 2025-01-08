/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_corpses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:53:49 by babischa          #+#    #+#             */
/*   Updated: 2025/01/08 18:21:08 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	clean_corpses(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philo)
	{
		pthread_join(table->philos[i].thread_id, NULL);
		pthread_mutex_destroy(&table->forks[i].fork_mutex);
		i++;
	}
	pthread_mutex_destroy(&table->mutex_printf);
	free(table->forks);
	free(table->philos);
	table->philos = NULL;
}
