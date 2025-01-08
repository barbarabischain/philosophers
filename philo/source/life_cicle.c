/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cicle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:14:50 by babischa          #+#    #+#             */
/*   Updated: 2025/01/08 18:35:11 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	taking_forks(t_philo *philo)
{
	if(philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork->fork_mutex);
		print_mutex(philo, HOLDING_FORK);
		pthread_mutex_lock(&philo->right_fork->fork_mutex);
		print_mutex(philo, HOLDING_FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork->fork_mutex);
		print_mutex(philo, HOLDING_FORK);
		pthread_mutex_lock(&philo->left_fork->fork_mutex);
		print_mutex(philo, HOLDING_FORK);
	}
}

void	eating(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork->fork_mutex);
	pthread_mutex_unlock(&philo->right_fork->fork_mutex);
	print_mutex(philo, EATING);
	usleep(philo->table->time_to_eat);
	philo->last_meal = get_time();
}

void	sleeping(t_philo *philo)
{
	print_mutex(philo, SLEEPING);
	usleep(philo->table->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_mutex(philo, THINKING);
}

void	*life_cicle(void	*arg)
{
	t_philo	*philo;
	int		meals;

	philo = (t_philo *) arg;
	meals = philo->table->number_of_meals;
	philo->last_meal = get_time();
	while ((meals == -1 || meals > 0) && !someone_is_dead(philo))
	{
		taking_forks(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
		if (meals != -1)
			meals--;
	}
	return (NULL);
}
