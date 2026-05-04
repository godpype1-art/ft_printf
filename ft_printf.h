/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:12:03 by falves-e          #+#    #+#             */
/*   Updated: 2026/05/04 17:39:56 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

int	handle_char(va_list *args);
int	handle_string(va_list *args);
int	handle_pointer(va_list *args);
int	handle_int(va_list *args);
int	handle_unsigned(va_list *args);
int	handle_hex_lower(va_list *args);
int	handle_hex_upper(va_list *args);
int	handle_percent(va_list *args);
int	ft_printf(const char *, ...);

#endif