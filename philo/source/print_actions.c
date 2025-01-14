/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:54:02 by babischa          #+#    #+#             */
/*   Updated: 2025/01/11 19:02:59 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_mutex(t_philo *philo, int action)
{
	long	current_time;

	if (philo_is_dead(philo) && action != DIE)
		return ;
	pthread_mutex_lock(&philo->table->mutex_printf);
	current_time = get_time() - philo->start_time;
	if (action == HOLDING_FORK)
		printf("%ld %d has taken a fork\n", current_time, philo->id);
	else if (action == EATING)
		printf("%ld %d is eating\n", current_time, philo->id);
	else if (action == THINKING)
		printf("%ld %d is thinking\n", current_time, philo->id);
	else if (action == SLEEPING)
		printf("%ld %d is sleeping\n", current_time, philo->id);
	else if (action == DIE)
		printf("%ld %d died\n", current_time, philo->id);
	pthread_mutex_unlock(&philo->table->mutex_printf);
}
