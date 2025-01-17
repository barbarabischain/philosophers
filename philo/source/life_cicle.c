/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cicle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:05:48 by babischa          #+#    #+#             */
/*   Updated: 2025/01/17 16:15:57 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	taking_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork->fork_mutex);
		print_actions(philo, HOLDING_FORK);
		pthread_mutex_lock(&philo->right_fork->fork_mutex);
		print_actions(philo, HOLDING_FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork->fork_mutex);
		print_actions(philo, HOLDING_FORK);
		pthread_mutex_lock(&philo->left_fork->fork_mutex);
		print_actions(philo, HOLDING_FORK);
	}
}

void	eating(t_philo *philo)
{
	if (philo->table->number_of_meals != -1)
		philo->meals_eaten++;
	pthread_mutex_lock(&philo->mutex_lastmeal);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->mutex_lastmeal);
	print_actions(philo, EATING);
	usleep(philo->table->time_to_eat * 1000);
	drop_forks(philo);
}

void	sleeping(t_philo *philo)
{
	print_actions(philo, SLEEPING);
	usleep(philo->table->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	print_actions(philo, THINKING);
	usleep(1000);
}

void	*life_cicle(void	*arg)
{
	t_philo		*philo;
	static void	(*f[4])(t_philo *) = {taking_forks, eating, sleeping, thinking};
	int			i;

	philo = (t_philo *) arg;
	while (check(philo))
	{
		f[i++](philo);
		if (i == 4)
			i = 0;
	}
	if (i == 1)
		drop_forks(philo);
	return (NULL);
}
