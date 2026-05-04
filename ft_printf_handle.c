/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:32:18 by falves-e          #+#    #+#             */
/*   Updated: 2026/05/04 18:18:17 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(va_list *args)
{
	char c;
	
	c = (char)va_arg(*args, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	handle_string(va_list *args)
{
	char	*str;

	str = (char *)va_arg(*args, char *);
	ft_putstr_fd(str, 1);
	return(ft_strlen(str));
}

int	handle_int(va_list *args)
{
	int		i;
	char	*str;
	
	i = va_arg(*args, int);
	str = itoa(i);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}


int	handle_unsigned(va_list *args)
{
	unsigned int	i;
	char			*str;
	
	i = va_arg(*args, unsigned int);
	str = ft_itoa(i);
	ft_putstr_fd(str, 1);
	return(ft_strlen(str));
}
