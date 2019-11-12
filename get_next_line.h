#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

typedef struct	s_buffer
{
	char		str[BUFFER_SIZE];
	int			index;
}				t_buffer;

#endif
