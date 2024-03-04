

#include "philo.h"

void    display_message(t_philo *p, char *s)
{
	t_big	*prg;

    prg = p->info;
	pthread_mutex_lock(&(prg->print_message));
	pthread_mutex_lock(&(prg->die));
	if (!(prg->flag_dead))
	{
		printf("%lld %d %s\n", (clock_now() - prg->start_prg), p->philo_id, s);
	}
	pthread_mutex_unlock(&(prg->die));
	pthread_mutex_unlock(&prg->print_message);
}

long long   clock_now()
{
    struct timeval p;

    gettimeofday(&p, 0);
    return ((p.tv_sec * 1000) + (p.tv_usec / 1000));
}
