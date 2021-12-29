#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	int				fd;
	char			*data;
	struct s_list	*next;
}				t_list;

void	ft_lstfreeone(t_list *lst);
void	ft_lstdelone(t_list **lst, t_list *del);
t_list	*ft_lstnew(int fd);
t_list	*ft_lstadd(t_list **lst, int fd);

int		get_next_line(int fd, char **line);

#endif