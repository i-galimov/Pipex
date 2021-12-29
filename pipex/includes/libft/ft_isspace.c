#include "../includes/libft.h"

bool	ft_isspace(char s)
{
	return (s == ' ' || (s >= 9 && s <= 13));
}
