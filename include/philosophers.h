/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:40:06 by babischa          #+#    #+#             */
/*   Updated: 2024/12/30 17:36:40 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef pthread_mutex_t t_mutex;
typedef struct s_table t_table;

typedef struct s_fork
{
    int     fork_id;
    t_mutex fork;
}   t_fork;

typedef struct s_philo
{
    int         id;
    pthread_t   thread_id;
    t_fork      *left_fork;
    t_fork      *right_fork;
    int         last_meal;
    int         nbr_of_meals;
}   t_philo;

typedef struct s_table
{
    long    nbr_of_philo;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    long    number_of_meals;
    long    start_time;
    int     end;
    t_fork  *forks;
    t_philo *philos;
}   t_table;



/*** UTILS ***/
long int	ft_atol(const char *nptr);


#endif
