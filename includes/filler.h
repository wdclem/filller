/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:51:35 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/17 15:26:22 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdarg.h>
# include <stdio.h> /* DELETE DELETE DELETE IDIOT */
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

/* Struct to keep miscelanous infos */
typedef struct	s_info{
				char	*line;
				char	player;
				char	enemy;
				int		col;
				int		row;
				int		move;
				int		**map;
}				t_info;

typedef	struct	s_piece{
				int		col;
				int		row;
				char	**shape;
}				t_piece;
				

typedef	struct	s_coord{
				int	x;
				int	y;
}				t_coord;

typedef struct	s_plateau{
				char	**plateau;
}				t_plateau;

int	main(int argc, char **argv);
int	player_info(t_info *info);	
int	map_info(t_info *info);
int	piece_info();
void    heat_map_init(t_info *info);
int	heat_map_fill(t_info *info, int val, int check);



#endif
