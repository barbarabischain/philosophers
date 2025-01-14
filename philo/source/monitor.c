/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:54:36 by babischa          #+#    #+#             */
/*   Updated: 2025/01/14 13:15:29 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	is_starving(t_philo *philo)
{
	long	last_meal_backup;

	pthread_mutex_lock(&philo->mutex_meal);
	last_meal_backup = get_time() - philo->last_meal;
	// pthread_mutex_lock(&philo->table->mutex_printf);
	// printf("philo %d, Last meal: %ld\n", philo->id, last_meal_backup);
	// pthread_mutex_unlock(&philo->table->mutex_printf);
	pthread_mutex_unlock(&philo->mutex_meal);
	if (last_meal_backup > philo->table->time_to_die)
	{
		print_mutex(philo, DIE);
		return (1);
	}
	return (0);
}

int	check_death(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philo)
	{
		if (is_starving(&table->philos[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	search_corpses(t_table *table)
{
	while (1)
	{
		usleep(100);
		if (check_death(table) == 1)
		{
			pthread_mutex_lock(&table->mutex_death);
			table->die = 1;
			pthread_mutex_unlock(&table->mutex_death);
			return ;
		}
	}
}
