#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp_b;

	i = 0;
	tmp_b = (unsigned char *) b;
	while (i < len)
	{
		*(tmp_b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
