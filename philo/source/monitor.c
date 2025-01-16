/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:54:36 by babischa          #+#    #+#             */
/*   Updated: 2025/01/16 11:46:38 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	find_corpse(t_table *table)
{
	int		i;
	long	last_meal_backup;

	i = 0;
	usleep(500);
	while (i < table->nbr_of_philo)
	{
		if (!check(&table->philos[i]))
			return (1);
		pthread_mutex_lock(&table->philos[i].mutex_lastmeal);
		last_meal_backup = get_time() - table->philos[i].last_meal;
		pthread_mutex_unlock(&table->philos[i].mutex_lastmeal);
		if (last_meal_backup > table->time_to_die)
		{
			pthread_mutex_lock(&table->mutex_death);
			table->die = 1;
			pthread_mutex_unlock(&table->mutex_death);
			print_actions(&table->philos[i], DIE);
			return (1);
		}
	}
	return (0);
}
