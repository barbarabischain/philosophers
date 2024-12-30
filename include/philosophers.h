/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:40:06 by babischa          #+#    #+#             */
/*   Updated: 2024/12/30 11:45:25 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


typedef struct s_philo
{
    int philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_meals;
}   t_philo;

#endif
