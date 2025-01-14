/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cicle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:14:50 by babischa          #+#    #+#             */
/*   Updated: 2025/01/14 13:18:05 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	taking_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
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
	pthread_mutex_lock(&philo->mutex_meal);
	philo->last_meal = get_time() + philo->table->time_to_eat;
	//philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->mutex_meal);
	print_mutex(philo, EATING);
	usleep(philo->table->time_to_eat * 1000);
	drop_forks(philo);
}

void	sleeping(t_philo *philo)
{
	print_mutex(philo, SLEEPING);
	usleep(philo->table->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	print_mutex(philo, THINKING);
}

void	*life_cicle(void	*arg)
{
	t_philo		*philo;
	static void	(*f[4])(t_philo *) = {taking_forks, eating, sleeping, thinking};
	int			i;

	philo = (t_philo *) arg;
	i = 0;
	if (philo->id % 2 != 0)
	 	usleep(42);
	while ((philo->nbr_of_meals == -1 || philo->nbr_of_meals > 0) && philo_is_dead(philo) == 0)
	{
		f[i++](philo);
		if (i == 4)
			i = 0;
		if (philo->nbr_of_meals != -1)
			philo->nbr_of_meals--;
		// pthread_mutex_lock(&philo->table->mutex_printf);
		// printf("philo %d: meals %d\n", philo->id, philo->nbr_of_meals);
		// pthread_mutex_unlock(&philo->table->mutex_printf);
	}
	if (i == 1)
		drop_forks(philo);
	return (NULL);
}
