/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 11:55:31 by falves-e          #+#    #+#             */
/*   Updated: 2026/05/04 18:09:58 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_flag(const char *format, va_list *args, int *count)
{
	if (*format == 'c')
		*count += handle_char(args);
	if (*format == 's')
		*count += handle_string(args);
	if (*format == 'p')
		*count += handle_pointer(args);
	if (*format == 'd' || *format == 'i')
		*count += handle_int(args);
	if (*format == 'u')
		*count += handle_unsigned(args);
	if (*format == 'x')
		*count += handle_hex_lower(args);
	if (*format == 'X')
		*count += handle_hex_upper(args);
	if (*format == '%')
		*count += handle_percent(args);
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
		format++;
	}
	va_end(args);
	return (count);
}
int main(void)
{
	//ft_printf("%c", 'c');
	printf("%d\n", ft_printf("%c\n", 'c'));
	return 0;
}
