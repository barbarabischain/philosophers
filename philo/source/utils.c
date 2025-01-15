/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:31:04 by babischa          #+#    #+#             */
/*   Updated: 2025/01/14 18:57:15 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	is_digit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	ft_isspace(char c)
{
	if ((c == ' ') || (c == '\f') || (c == '\n') || (c == '\r') || (c == '\v')
		|| (c == '\t'))
		return (1);
	else
		return (0);
}

long int	ft_atol(const char *nptr)
{
	int			i;
	long int	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if ((nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		num = num * 10;
		num = num + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}

//void print_variaveis(t_table *table)
// {
// 	int	i = 0;

// 	while (i < table->nbr_of_philo)
// 	{
// 		printf("philo id     %d\n", table->philos[i].id);
// 		printf("left fork    %d\n", table->philos[i].left_fork->fork_id);
// 		printf("right fork   %d\n", table->philos[i].right_fork->fork_id);
// 		printf("nbr of meals %d\n", table->philos->nbr_meals);
// 		printf("last_meal    %ld\n", table->philos[i].last_meal);
// 		printf("start_time   %ld\n\n", table->philos[i].start_time);
// 		i++;
// 	}
// }
