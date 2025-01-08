/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:54:36 by babischa          #+#    #+#             */
/*   Updated: 2025/01/08 19:38:59 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	someone_is_dead(t_philo	*philo)
{
	if (get_time() - philo->last_meal > (philo->table->time_to_die / 1000))
	{
		printf("entrei aqui\n");
		philo->table->die = 1;
		printf("PHILO %d DIED!", philo->id);
		return (1);
	}
	return (0);
}
