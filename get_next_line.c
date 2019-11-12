#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

static int		ft_chkendl(const char *buffer, int index, char *to_write)
{
	while (index <= BUFFER_SIZE && buffer[index] != '\n')
		*to_write++ = buffer[index++];
	if (index <= BUFFER_SIZE && buffer[index] == '\n')
	{
		*to_write = 0;
		return (index + 1);
	}
	return (-1);
}

static void		ft_secondread(t_buffer buffer, char *line)
{
	char	*buf;
	int		start;

	buf = buffer.str;
	start = buffer.index;
	while (start < BUFFER_SIZE)
	{
		*line++ = *buf++;
		start++;
	}
	*line = 0;
	buffer.index = 0;
}

int				ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void			*ft_realloc(void *ptr, size_t size)
{
	unsigned char	*new_ptr;
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)ptr;
	if (!(new_ptr = (unsigned char *)malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_ptr[i] = p[i];
		i++;
	}
	return (new_ptr);
}

int				get_next_line(int fd, char **line)
{
	static t_buffer		buffer = { 0 };
	int				res_read;
	int				res_chkendl;
	int				i;

	res_chkendl = 1;
	i = 0;
	if (!(*line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (*(buffer.str))
		ft_secondread(buffer, *line);
	while ((res_read = read(fd, buffer.str, BUFFER_SIZE)) != -1 && res_read
			&& res_chkendl == -1)
	{
		printf("got here");
		*line = (char *)ft_realloc(*line, BUFFER_SIZE + ft_strlen(*line) + 1);
		res_chkendl = ft_chkendl(buffer.str, buffer.index, *line + BUFFER_SIZE * i++);
		buffer.index = (res_chkendl == BUFFER_SIZE) ? 0 : res_chkendl;
		printf("buffer.index = %d\n", buffer.index);
	}
	//*line = (char *)ft_realloc(*line, ft_strlen(*line) + 1);
	//*(*line + ft_strlen(*line)) = 0;
	return (1);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	i;

	if (!(result = (char *)malloc(sizeof(char) * (strlen(s1) + 1))))
		return (NULL);
	i = 0;
	while (i++ < strlen(s1))
		result[i - 1] = s1[i - 1];
	result[i - 1] = 0;
	return (result);
}

int		main(int ac, char **av)
{
	int fd;
	char *line = NULL;

	if (ac < 2)
	{
		printf("%s: filename missing\n", av[0]);
		return (1);
	}
	printf("File name : %s\n", av[1]);

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("%s: ERROR: %s\n", av[0], strerror(errno));
		return (1);
	}
	printf("File opened in reading mode\n");
	printf("Begin reading\n");

	get_next_line(fd, &line);
	//printf("line:\n#%s#\n", line);

	close(fd);
	if (line)
		free(line);
	return (0);
}

// int main()
// {
// 	char *buffer = ft_strdup("bonjour\nje suis une bite bonjour");
// 	char *start = buffer, *line;
	
// 	if (!(line = (char *)malloc(BUFFER_SIZE)))
// 		return (2);
// 	write(1, "buffer = ", 10);
// 	write(1, buffer, BUFFER_SIZE);
// 	write(1, "|END BUFFER\nresult = ", 22);

// 	int result = ft_chkendl(buffer, 0, line);
// 	write(1, buffer + result, BUFFER_SIZE - result);
// 	printf("|END RESULT\nnb = %d\nstr = %s\n", result, line);

// 	free(start);
// 	free(line);
// 	return (0);
// }
