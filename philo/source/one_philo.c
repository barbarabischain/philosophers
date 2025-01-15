/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:15:19 by babischa          #+#    #+#             */
/*   Updated: 2025/01/14 19:04:24 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	printf("entrei no one philo\n");
	pthread_mutex_lock(&philo->left_fork->fork_mutex);
	print_actions(philo, HOLDING_FORK);
	usleep(philo->table->time_to_die * 1000);
	pthread_mutex_unlock(&philo->left_fork->fork_mutex);
	return (NULL);
}
