/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:24:10 by babischa          #+#    #+#             */
/*   Updated: 2025/01/15 15:46:37 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	philo_is_dead(t_philo *philo)
{
	int	life_status;

	pthread_mutex_lock(&philo->table->mutex_death);
	life_status = philo->table->die;
	pthread_mutex_unlock(&philo->table->mutex_death);
	return (life_status);
}

int	is_able_to_eat(t_philo *philo)
{
	if (philo->table->number_of_meals == -1)
		return (1);
	else
	{
		if (philo->meals_eaten < philo->table->number_of_meals)
			return (1);
	}
	return (0);
}

int	check(t_philo *philo)
{
	if (is_able_to_eat(philo) && (!philo_is_dead(philo)))
		return (1);
	return (0);
}
