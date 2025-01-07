/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:40:06 by babischa          #+#    #+#             */
/*   Updated: 2025/01/07 14:30:28 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef pthread_mutex_t t_mutex;
typedef struct s_table t_table;

enum e_actions
{
    HOLDING_FORK,
    EATING,
    THINKING,
    SLEEPING,
};

typedef struct s_fork
{
    int     fork_id;
    t_mutex fork_mutex;
}   t_fork;

typedef struct s_philo
{
    int         id;
    pthread_t   thread_id;
    t_fork      *left_fork;
    t_fork      *right_fork;
    int         last_meal;
    int         nbr_of_meals;
    t_table     *table;
}   t_philo;

typedef struct s_table
{
    long            nbr_of_philo;
    long            time_to_die;
    long            time_to_eat;
    long            time_to_sleep;
    long            number_of_meals;
    long            start_time;
    int             end;
    t_fork          *forks;
    t_philo         *philos;
    pthread_mutex_t mutex_printf;
}   t_table;

/*** FUNCTIONS ***/
void	    print_mutex(t_philo *philo, int action);
void        forge_forks(t_table *table);
void	    *life_cicle(void	*arg);
void	    clean_corpses(t_table *table);

/*** UTILS ***/
long        get_time(void);
long int	ft_atol(const char *nptr);
int	        is_digit(char *str);

#endif
