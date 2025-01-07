/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forge_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:36:12 by babischa          #+#    #+#             */
/*   Updated: 2025/01/07 14:30:53 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void forge_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(t_fork) * table->nbr_of_philo);
	memset(table->forks, 0, sizeof(t_fork) * table->nbr_of_philo);
	while (i < table->nbr_of_philo)
	{
		table->forks[i].fork_id = i;
		pthread_mutex_init(&table->forks[i].fork_mutex, NULL);
		i++;
	}
}
