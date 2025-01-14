/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:40:06 by babischa          #+#    #+#             */
/*   Updated: 2025/01/14 13:44:26 by babischa         ###   ########.fr       */
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

typedef pthread_mutex_t	t_mutex;
typedef struct s_table	t_table;

enum e_actions
{
	HOLDING_FORK,
	EATING,
	THINKING,
	SLEEPING,
	DIE
};

typedef struct s_fork
{
	int		fork_id;
	t_mutex	fork_mutex;
}	t_fork;

typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	t_fork			*left_fork;
	t_fork			*right_fork;
	long			last_meal;
	long			start_time;
	int				nbr_of_meals;
	pthread_mutex_t	mutex_meal;
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	long			nbr_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			number_of_meals;
	int				die;
	t_fork			*forks;
	t_philo			*philos;
	pthread_mutex_t	mutex_printf;
	pthread_mutex_t	mutex_death;
}	t_table;

/*** FUNCTIONS ***/
void		*life_cicle(void *arg);
void		print_mutex(t_philo *philo, int action);
void		forge_forks(t_table *table);
void		search_corpses(t_table *table);
void		clean_corpses(t_table *table);
int			philo_is_dead(t_philo *philo);
void		drop_forks(t_philo *philo);
void		*one_philo(void *arg);

/*** UTILS ***/
long		get_time(void);
long int	ft_atol(const char *nptr);
int			is_digit(char *str);

#endif
