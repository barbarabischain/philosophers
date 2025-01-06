/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:54:02 by babischa          #+#    #+#             */
/*   Updated: 2025/01/06 12:31:33 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_mutex(t_philo *philo, int action)
{
	//se todos estiverem
	//mutex
	if (action == HOLDING_FORK)
		printf("%d has taken a fork\n", philo->id);
	else if (action == EATING)
		printf("%d is eating\n", philo->id);
	else if (action == THINKING)
		printf("%d is thinking\n", philo->id);
	else if (action == SLEEPING)
		printf("%d is sleeping\n", philo->id);
}
