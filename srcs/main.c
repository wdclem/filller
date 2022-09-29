/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:28:01 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/29 18:34:34 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//la bite de raoul est abberante

#include <stdio.h>
#include "../includes/filler.h"

void	clean_exit(int **array, int len)
{
	int	i;

	i = 0;
	while(i < len)
	{
		free(info->map[i]);
		i++;
	}
	free(info->map);
}


void		reset_heat(t_info *info)
{
	int		y;
	int		x;

	y = -1;
	while (++y < 20)
	{
		x = -1;
		while (++x < 20)
			info->heatmap[y][x] = EMPTY;
	}
}

int	reset_struct(t_info *info, t_piece *piece)
{
	piece->shape = NULL;
	info->elem = 0;
	info->p_col = 0;
	info->p_row = 0;
	info->s_row = 20000;
	info->s_col = 20000;
	info->b_row = 0;
	info->b_col = 0;
	info->map = NULL;
	
	return (1);
}

int	print_position(t_info *info)
{
	if (info->sum < PLAYER || info->sum >= ENEMY)
	{
		ft_printf("0 0\n");
		return (0);
	}
	else
		ft_printf("%d %d\n", info->b_row, info->b_col);
	return(1);
}

int	main(void)
{
	t_info	*info;
	t_piece	*piece;

//	if (!argc || !argv)
//		ft_printf("oalala no argc");
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (-1);
	if (!(piece = (t_piece*)malloc(sizeof(t_piece))))
		return (-1);
	player_info(info);
	get_map_dim(info);
	while(1)
	{
		reset_struct(info, piece);
		map_info(info);
		create_heat_map(info);
		piece_info(info, piece);
		set_position(info, piece);
		reset_heat(info);
		if(!(print_position(info)))
		{
			clean_exit(info->map, (
				break;
	}
	return (0);
}

