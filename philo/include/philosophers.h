/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:40:06 by babischa          #+#    #+#             */
/*   Updated: 2025/01/15 15:48:16 by babischa         ###   ########.fr       */
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
	int			fork_id;
	t_mutex		fork_mutex;
}	t_fork;

typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	t_fork			*left_fork;
	t_fork			*right_fork;
	long			last_meal;
	long			start_time;
	int				meals_eaten;
	pthread_mutex_t	mutex_lastmeal;
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
	pthread_mutex_t	mutex_death;
	pthread_mutex_t	mutex_printf;
	t_philo			*philos;
	t_fork			*forks;
}	t_table;

/*** FUNCTIONS ***/
void		set_table(t_table *table, char **argv);
void		forge_forks(t_table *table);
void		drop_forks(t_philo *philo);
void		philosophers_birth(t_table *table);
void		*life_cicle(void	*arg);
void		*one_philo(void *arg);
void		print_actions(t_philo *philo, int action);
void		clean_corpses(t_table *table);
int			is_able_to_eat(t_philo *philo);
int			check(t_philo *philo);
int			find_corpse(t_table *table);
int			philo_is_dead(t_philo *philo);

/*** UTILS ***/
long		get_time(void);
int			is_digit(char *str);
long int	ft_atol(const char *nptr);

#endif
