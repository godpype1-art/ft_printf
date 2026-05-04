/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 18:11:22 by falves-e          #+#    #+#             */
/*   Updated: 2026/05/04 19:09:12 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	putnbr_base(long nb, char *base, int *result_len)
{
	if (nb )
}
int	handle_pointer(va_list *args)
{
	long	i;
	char	*base;
	int		result_len;

	result_len = 0;
	base = "0123456789abcdef";
	i = va_arg(*args, long);
	putnbr_base(i, base, result_len);
	return (result_len);	
}
int	handle_hex_lower(va_list *args)
{
	int		i;
	char	*base;
	int		result_len;

	result_len = 0;
	base = "0123456789abcdef";
	i = va_arg(*args, long);
	putnbr_base(i, base, result_len);
	return (result_len);	
}

int	handle_hex_upper(va_list *args)
{
	int		i;
	char	*base;
	int		result_len;

	result_len = 0;
	base = "0123456789ABCDEF";
	i = va_arg(*args, long);
	putnbr_base(i, base, result_len);
	return (result_len);	
}
