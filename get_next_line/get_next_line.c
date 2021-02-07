#include "get_next_line.h"

char	*ft_strjoin(char *str, char c)
{
	int		len;
	char	*ret;

	len = 0;
	while (str[len])
		len++;
	if (!(ret = malloc((len + 2) * sizeof(char))))
		return (0);
	len = 0;
	while (str[len])
	{
		ret[len] = str[len];
		len++;
	}
	ret[len] = c;
	ret[len + 1] = '\0';
	free(str);
	return (ret);
}


int	get_next_line(char **line)
{
	int		ret;
	char	*str;
	char	*buffer;

	buffer = malloc(2 * sizeof(char));
	if (!line || !(str = malloc(1 * sizeof(char))) || !buffer)
		return (-1);
	str[0] = '\0';
	while ((ret = read(0, buffer, 1) > 0))
	{
		if (buffer[0] == '\n')
			break;
		str = ft_strjoin(str, buffer[0]);
	}
	free(buffer);
	*line = str;
	return (ret);
}		