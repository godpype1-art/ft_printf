/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 11:55:31 by falves-e          #+#    #+#             */
/*   Updated: 2026/05/13 15:32:28 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_flag(const char *format, va_list *args, int *count)
{
	if (*format == 'c')
		*count += handle_char(args);
	else if (*format == 's')
		*count += handle_string(args);
	else if (*format == 'p')
		*count += handle_pointer(args);
	else if (*format == 'd' || *format == 'i')
		*count += handle_int(args);
	else if (*format == 'u')
		*count += handle_unsigned(args);
	else if (*format == 'x')
		*count += handle_hex_lower(args);
	else if (*format == 'X')
		*count += handle_hex_upper(args);
	else if (*format == '%')
		*count += handle_percent();
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format += handle_flag(format + 1, &args, &count);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		if (*format)
			format++;
	}
	va_end(args);
	return (count);
}
/* int main(void)
{
	int i = 7574846;
	
	printf("%", ft_printf("flag = %X\n", i));
	printf("%", printf("flag = %X\n", i));

	ft_printf("%");
	printf("teste\n");
	printf("ori %\n");
	return 0;
} */
