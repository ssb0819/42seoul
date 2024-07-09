#include "philo_bonus.h"

/*
한 프로세스 종료하면 sigint 보내지말고 sigusr보내서 핸들러에서 세마포어 다 언락하고 닫고 종료하는 걸로 바꿔보기 
(전역변수 못쓰니까 안됨... 기존껄로 가자)
-> 이때 1. 락 상태에서 클로즈하면? 2. 락 상태아닌데 언락하면? 테스트 해보고 찾아보기 
--> 뮤텍스랑 원리 다름 세마포어는 값을 바꿔주는 애니까 다 에러안나고 잘됨 기존에 락상태, 언락상태 신경 안씀
다 하고 난 후 릭체크, 어드레스 새니타이저 쓰레드 체크
*/

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("get sigint \n");
	}
}

int	main(void)
{
	sem_t	*sem;

	sem_unlink("test");
	sem = sem_open("test", O_CREAT, 666, 1);
	if (sem_wait(sem) < 0)
	{
		perror("sem_wait  error\n");
	}
	sleep(5);
	if (sem_post(sem) < 0)
	{
		perror("sem_post error\n");
	}
	if (sem_close(sem) < 0)
	{
		perror("sem_close error\n");
	}
	if (sem_unlink("test") < 0)
	{
		perror("sem_unlink error\n");
	}
}

static void	simulate(int ph_cnt, t_philo *philo)
{
	int		child_cnt;
	int		status;
	pid_t	result;

	create_philo(ODD, philo, ph_cnt);
	if (ph_cnt > 1)
	{
		usleep(philo->time_to_eat / 2 * 1000);
		create_philo(EVEN, philo, ph_cnt);
	}
	child_cnt = 0;
	while (1)
	{
		result = waitpid(-1, &status, WNOHANG);
		if (result == 0)
		{
			usleep(10000);
			continue ;
		}
		else if (result == -1)
			return ;
		else
		{
			if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			{
				if (++child_cnt == ph_cnt)
					return ;
			}
			else
			{
				philo->philo_num = WEXITSTATUS(status);
				print_state(philo, "died");
				kill(0, SIGINT);
			}
		}
	}
}


static t_philo	*philo_init(char **argv)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		print_err_and_exit("Error: Malloc Error\n");
	memset(philo, 0, sizeof(t_philo));
	set_time_args(philo, argv);
	return (philo);
}

static void	set_time_args(t_philo *philo, char **argv)
{	
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_limit;

	time_to_die = ph_atoi(argv[2]);
	time_to_eat = ph_atoi(argv[3]);
	time_to_sleep = ph_atoi(argv[4]);
	if (time_to_die < 0 || time_to_eat < 0 || time_to_sleep < 0)
		print_err_and_exit("Error: Initialization error - Check the args\n");
	philo->time_to_die = time_to_die;
	philo->time_to_eat = time_to_eat;
	philo->time_to_sleep = time_to_sleep;
	if (argv[5])
	{
		eat_limit = ph_atoi(argv[5]);
		if (eat_limit < 0)
			print_err_and_exit("Error: Initialization error - Check the args\n");
		philo->eat_limit = eat_limit;
	}
	else
		philo->eat_limit = 0;
	philo->start_time = get_timestamp(0);
	philo->last_meal.time = 0;
}
