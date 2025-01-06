/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:54:02 by babischa          #+#    #+#             */
/*   Updated: 2025/01/06 18:04:37 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_mutex(t_philo *philo, int action)
{
	pthread_mutex_lock(&philo->table->mutex_printf);
	if (action == HOLDING_FORK)
		printf("%ld %d has taken a fork\n", (get_time() - philo->table->start_time), philo->id + 1);
	else if (action == EATING)
		printf("%ld %d is eating\n", (get_time() - philo->table->start_time), philo->id + 1);
	else if (action == THINKING)
		printf("%ld %d is thinking\n", (get_time() - philo->table->start_time), philo->id + 1);
	else if (action == SLEEPING)
		printf("%ld %d is sleeping\n",(get_time() - philo->table->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->table->mutex_printf);
}
