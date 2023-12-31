/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:29:40 by pfalli            #+#    #+#             */
/*   Updated: 2023/12/15 11:59:56 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int print_element(char element, va_list ap)
{
	int count;

	if (element == 'c')
		count += ft_print_char(va_arg(ap, int));
	if (element == 's')
		return(ft_print_string(ap)); // there are 2 ways to do it //
}



int ft_printf(const char *format, ...)
{
	va_list ap;
	int count = 0;
	va_start(ap, format);

	while(*format)
	{
		if (*format == '%' && (*format +1) == 0)
			break;
		else if (*format == '%')
			count += print_element(ap, *(format++));
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return(count);
}


int main()
{
	ft_printf("Sono di Roma");
	return 0;
}