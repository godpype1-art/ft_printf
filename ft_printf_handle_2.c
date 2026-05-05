/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 18:11:22 by falves-e          #+#    #+#             */
/*   Updated: 2026/05/05 14:21:00 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_base(long nb, char *base, size_t base_len, int *result_len)
{
	if (nb < (long)base_len)
	{
		write(1, &base[nb], 1);
		(*result_len)++;
	}
	else
	{
		putnbr_base(nb / base_len, base, base_len, result_len);
		putnbr_base(nb % base_len, base, base_len, result_len);
	}
	return (*result_len);
}
int	handle_pointer(va_list *args)
{
	void *		i;
	char		*base;
	int			result_len;
	const char	*str = "(nil)";
	
	result_len = 2;
	i = va_arg(*args, void *);
	if (i == NULL)
	{
		ft_putstr_fd((char *)str, 1);
		return (ft_strlen(str));
	}
	ft_putstr_fd("0x", 1);
	base = "0123456789abcdef";
	putnbr_base((unsigned long)i, base, ft_strlen(base), &result_len);
	return (result_len);	
}
int	handle_hex_lower(va_list *args)
{
	unsigned int	i;
	char			*base;
	int				result_len;

	result_len = 0;
	base = "0123456789abcdef";
	i = va_arg(*args, unsigned int);
	putnbr_base((long)i, base, ft_strlen(base), &result_len);
	return (result_len);	
}

int	handle_hex_upper(va_list *args)
{
	unsigned int	i;
	char			*base;
	int				result_len;

	result_len = 0;
	base = "0123456789ABCDEF";
	i = va_arg(*args, unsigned int);
	putnbr_base((long)i, base, ft_strlen(base), &result_len);
	return (result_len);	
}

int	handle_unsigned(va_list *args)
{
	unsigned int	i;
	char			*base;
	int				result_len;
	
	base = "0123456789";
	result_len = 0;
	i = va_arg(*args, unsigned int);
	putnbr_base((long) i, base, ft_strlen(base), &result_len);
	return(result_len);
}
