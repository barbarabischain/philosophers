/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:08:33 by babischa          #+#    #+#             */
/*   Updated: 2025/01/15 17:31:51 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	set_table(t_table *table, char **argv)
{
	table->nbr_of_philo = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	table->die = 0;
	if (argv[5] && argv[5] > 0)
		table->number_of_meals = ft_atol(argv[5]);
	else
		table->number_of_meals = -1;
	pthread_mutex_init(&table->mutex_death, NULL);
	pthread_mutex_init(&table->mutex_printf, NULL);
	forge_forks(table);
}
