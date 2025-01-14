/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:24:10 by babischa          #+#    #+#             */
/*   Updated: 2025/01/13 14:01:41 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	philo_is_dead(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->table->mutex_death);
	result = philo->table->die;
	pthread_mutex_unlock(&philo->table->mutex_death);
	return (result);
}
