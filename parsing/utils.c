#include "parsing.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;
	int len;

	i = 0;
	sign = 1;
	result = 0;
	len = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		++i;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = (sign * (-1));
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		++i;
		++len;
	}
	result = (result * sign);
	return (result);
}

int	ft_isdigit(int c)
{
	//printf (" c v isdigit char c[%c] int c[%d]\n", c, c);
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}


char	*ft_strdup(const char *str)

{
	int		i;
	int		len;
	char	*copy;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (0);
	while (i < len)
	{
		copy[i] = str[i];
		++i;
	}
	copy[len] = '\0';
	return (copy);
}


int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}