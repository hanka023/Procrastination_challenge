
#include "parsing.h"


// 1. Klasický strlen
int	ft_strlen(char *s)
{
	int	i = 0;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

// 2. Strjoin, který ROVNOU uvolňuje starý buffer (šetří řádky kódu)
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i = 0;
	int		j = 0;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1); // DŮLEŽITÉ: automaticky uvolní starý buffer!
	return (str);
}

char *get_next_line (int fd)
{
	char *line;
	int i = 0;
	int j = 0;
	int len = 0;
	ssize_t n = 1;

	static char buffer[BUFFER_SIZE + 1];   //chci misto na '\0'
 
	if (fd < 0 || fd > 10240 || BUFFER_SIZE < 0 )
	{
		perror ("Error");
		return (NULL);
	}
	line = NULL;

	while (1)
	{
		i = 0;
		if (!buffer[0])
		{
			n =  (read(fd, buffer, BUFFER_SIZE));
			if (n <= 0)
				break;
			buffer[n] = '\0';
		}
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);

		while (buffer[i] && buffer[i] != '\n')
			++i;

		if (buffer[i] == '\n')
		{	
			len = ft_strlen(line) - ft_strlen(buffer) + i + 1;
			line[len] = '\0';
			j = 0;
			++i;
			while (buffer[i])
				buffer[j++] = buffer[i++];
			buffer[j] = '\0';
			return (line);
		}
		buffer[0] = '\0';
	}
	return (line);
}

// int get_next_line(int fd)
// {
// 	//int fd;
// 	char *line;

// 	//fd = open("text.txt", O_RDONLY);
// 	if (fd < 0)
// 		return (1);

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf ("%s",line);
// 		free(line);
// 	}
// 	close (fd);
// 	return (0);
// }