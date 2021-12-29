#include "../includes/libft.h"

void	ft_putnbr_fd(int fd, int n)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd(fd, n / 10);
		ft_putnbr_fd(fd, -(n % 10));
	}
	else if (n < 0)
	{
		ft_putchar_fd(fd, '-');
		ft_putnbr_fd(fd, -n);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(fd, n / 10);
		ft_putnbr_fd(fd, n % 10);
	}
	else
	{
		ft_putchar_fd(fd, n + 48);
	}
}
