#include "libft.h"

int	ft_isint(char *str)
{
	int			i;
	intmax_t	j;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	j = ft_atoi(str);
	if (j != (int)j)
		return (0);
	if (str[0] == '-' && i == 1)
		return (0);
	return (1);
}
