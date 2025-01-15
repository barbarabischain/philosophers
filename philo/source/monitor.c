/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:54:36 by babischa          #+#    #+#             */
/*   Updated: 2025/01/15 15:47:27 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	is_starving(t_philo *philo)
{
	long	last_meal_backup;

	pthread_mutex_lock(&philo->mutex_lastmeal);
	last_meal_backup = get_time() - philo->last_meal;
	pthread_mutex_unlock(&philo->mutex_lastmeal);
	if (last_meal_backup > philo->table->time_to_die)
		return (1);
	return (0);
}

int	find_corpse(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philo)
	{
		if (is_starving(&table->philos[i]))
		{
			pthread_mutex_lock(&table->mutex_death);
			table->die = 1;
			pthread_mutex_unlock(&table->mutex_death);
			return (1);
		}
	}
	return (0);
}
