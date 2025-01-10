/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:54:36 by babischa          #+#    #+#             */
/*   Updated: 2025/01/10 18:43:07 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int is_starving(t_philo *philo)
{
	long	last_meal_backup;


	pthread_mutex_lock(&philo->mutex_meal);
	last_meal_backup = philo->last_meal;
	pthread_mutex_unlock(&philo->mutex_meal);
//	printf("(is startving) philo: %d, last meal: %ld\n",philo->id, last_meal_backup);
	// printf("philo %d, current time %ld, time last meal: %ld, time difference: %ld time to die : %ld\n", philo->id, get_time(),
	// last_meal_backup, get_time() - last_meal_backup, philo->table->time_to_die);
	if ((get_time() - last_meal_backup) > (philo->table->time_to_die))
		return (1);
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
		if (check_death(table) == 1)
		{
			pthread_mutex_lock(&table->mutex_death);
			table->die = 1;
			print_mutex(table->philos, DIE);
			pthread_mutex_unlock(&table->mutex_death);
			return;
		}
		usleep(2000);
	}
}
