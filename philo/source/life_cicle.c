/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cicle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:14:50 by babischa          #+#    #+#             */
/*   Updated: 2025/01/07 14:39:29 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// void	taking_forks(t_philo *philo)
// {

// }

void	eating(t_philo *philo)
{
	print_mutex(philo, EATING);
	usleep(philo->table->time_to_eat); //time to eat esta em milisegundo -> passar para micro (dica)
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
	while (meals > 0)
	{
		//peegou o garfo
		eating(philo);
		sleeping(philo);
		thinking(philo);
		meals--;
	}
	return (NULL);
}
