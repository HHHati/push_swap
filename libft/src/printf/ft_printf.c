/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:43:59 by bade-lee          #+#    #+#             */
/*   Updated: 2026/01/15 16:02:49 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_apply_param(int param, va_list params, int *counter)
{
	static int	(*function[9])(int *, va_list) =
		{&param_c, &param_s, &param_p, &param_d, &param_i,
		&param_u, &param_xlow, &param_xup, &param_prc};

	function[param](counter, params);
}

int	ft_printf(const char *param, ...)
{
	static char	*options = "cspdiuxX%";
	size_t		i;
	int		counter;
	va_list		list;

	i = 0;
	counter = 0;
	va_start(list, param);
	while (param[i])
	{
		if (param[i] == '%' && ft_strchr(options, param[i + 1]))
		{
			ft_apply_param(ft_strchr(options, param[i + 1]) - options,
				list, &counter);
			i++;
		}
		else
		{
			write(1, &param[i], 1);
			counter++;
		}
		i++;
	}
	va_end(list);
	return (counter);
}
