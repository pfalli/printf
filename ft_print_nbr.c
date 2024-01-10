/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:06:05 by pfalli            #+#    #+#             */
/*   Updated: 2024/01/08 20:06:05 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	digit;

	digit = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			digit = n + 48;
			write(fd, &digit, 1);
		}
	}
}


int len_nbr(int nbr)
{
    int length = 0;

    if(nbr <= 0)
        length++;
    while (nbr != 0)
    {
        nbr = nbr / 10;
        length++;
    }
    return(length);

}


int ft_print_nbr(int nbr)
{
    int count = 0;

    count = len_nbr(nbr);
    ft_putnbr_fd(nbr, 1);
    return(count);
}

int main()
{
    int number = 37468;
    int result = ft_print_nbr(number);


}