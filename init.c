/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:11:05 by bade-lee          #+#    #+#             */
/*   Updated: 2026/01/15 15:59:56 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**manage_param(char **argv, int argc)
{
	char	**infos;
	int		i;

	i = 0;
	if (argc == 2)
	{
		infos = ft_split(argv[1], ' ');
		if (!infos)
			return (0);
	}
	else
	{
		infos = malloc(argc * sizeof(char *));
		if (!infos)
			return (0);
		while (++i < argc)
		{
			infos[i - 1] = ft_strdup(argv[i]);
			if (!infos[i - 1])
				free_infos(infos, 1);
		}
		infos[i - 1] = 0;
	}
	return (infos);
}

void	box_init(t_infos *global_infos, char **infos)
{
	int	n;
	int	i;

	n = global_infos->len - 1;
	i = 0;
	global_infos->box = malloc(global_infos->len * sizeof(int));
	if (!global_infos->box)
	{
		free(global_infos);
		free_infos(infos, 1);
	}
	while (n > -1)
	{
		global_infos->box[i] = ft_atoi(infos[n]);
		n--;
		i++;
	}
	free_infos(infos, 0);
}

void	box_index(t_infos *global_infos)
{
	int	i;
	int	*new_box;

	swap_box(global_infos);
	new_box = malloc(global_infos->len * sizeof(int));
	if (!new_box)
		free_box(global_infos, 1);
	i = 0;
	get_max(global_infos, new_box);
	while (i < global_infos->len - 1)
	{
		get_min(global_infos, i, new_box);
		i++;
	}
	free(global_infos->box);
	global_infos->box = new_box;
}

t_infos	*init_infos(char **argv, int argc)
{
	char	**infos;
	t_infos	*global_infos;

	infos = manage_param(argv, argc);
	if (!infos || !atoi_check(infos) || !check_double_stack(infos))
	{
		error();
	}
	if (!infos[0])
		free_infos(infos, 1);
	global_infos = malloc(sizeof(t_infos));
	if (!global_infos)
		free_infos(infos, 1);
	global_infos->len = 0;
	while (infos[global_infos->len])
		global_infos->len = global_infos->len + 1;
		global_infos->sep = global_infos->len;
	box_init(global_infos, infos);
	box_index(global_infos);
	return (global_infos);
}
