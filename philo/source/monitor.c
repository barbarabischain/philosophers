/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:54:36 by babischa          #+#    #+#             */
/*   Updated: 2025/01/08 18:21:16 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	someone_is_dead(t_philo	*philo)
{	if (get_time() - philo->last_meal > philo->table->time_to_die)
	{
		philo->table->die = 1;
		printf("PHILO %d DIED!", philo->id);
		return (1);
	}
	return (0);
}
