#include "philosophers.h"

void    app_error(void)
{
    printf("Error: app crashed\n");
    exit(1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	res = 0;
	sign = 1;
	if (!(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		app_error();
	if (str[i] == '-')
		app_error();
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
