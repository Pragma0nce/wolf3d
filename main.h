/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:33:57 by kcoetzee          #+#    #+#             */
/*   Updated: 2017/07/13 16:41:56 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MAIN_H
# define MAIN_H
#include <stdlib.h>
#include "mlx.h"
#include<math.h>
#include <stdio.h>

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#define mapWidth 24
#define mapHeight 24
typedef	struct	s_vector2
{
	double	x;
	double	y;
}				t_vector2;

typedef	struct	s_vector2i
{
	int		x;
	int		y;
}				t_vector2i;	

typedef	struct	s_raycast
{
	t_vector2	pos;
	t_vector2	dir;
}				t_raycast;

typedef	struct	s_camera
{
	t_vector2	plane;
	t_vector2	pos;
	t_raycast	ray;
}				t_camera;

typedef	struct	s_player
{
	t_vector2	pos;
	t_vector2	dir;

	t_camera	view;
}				t_player;

int		dda_loop(t_vector2 *side_dist, t_vector2 *delta_dist, t_vector2 *step, t_vector2 *ray, int **world_map);
void	dda(t_raycast *ray, int **world_map);
void 	draw_line(int x1,int y1, int x2, int y2, void *mlx, void *win, int color);
