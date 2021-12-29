#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = 0;
	if (dstsize < destlen + 1)
		return (dstsize + srclen);
	if (dstsize > destlen + 1)
	{
		while (src[i] != '\0' && destlen + 1 + i < dstsize)
		{
			dest[destlen + i] = src[i];
			i++;
		}
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
