#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if ((n == 0) || (dst == src))
		return (dst);
	i = 0;
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	while (i < n)
	{
		*(tmp_dst + i) = *(tmp_src + i);
		i++;
	}
	return (dst);
}
