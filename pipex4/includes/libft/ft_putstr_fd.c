#include "../includes/libft.h"

void	ft_putstr_fd(int fd, char *str)
{
	if (str == NULL)
		return ;
	write(fd, str, ft_strlen(str));
}
