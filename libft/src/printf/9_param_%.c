/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_param_%.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:01:21 by bade-lee          #+#    #+#             */
/*   Updated: 2026/01/15 16:02:13 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	param_prc(int *counter, va_list params)
{
	(void)params;
	ft_putchar_fd('%', 1);
	*counter = *counter + 1;
	return (1);
}
