/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:36:13 by kcoetzee          #+#    #+#             */
/*   Updated: 2017/07/17 11:08:21 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	dda_loop(t_vector2 *side_dist, t_vector2 *delta_dist, t_vector2 *step, t_vector2 *ray, int **world_map)
{
	int			hit;
	int			side;
	t_vector2i	map;

	map.x = (int)ray->pos.x;
	map.y = (int)ray->pos.y;

	hit = 0;
	while (hit == 0)
	{
		if (side_dist->x < side_dist->y)
		{
			side_dist->x += delta_dist->x;
			map.x += step->x;
			side = 0;
		}
		else
		{
			side_dist->y += delta_dist->y;
			map.y += step->y;
			side = 1;
		}
		if (world_map[map.x][map.y] > 0)
			return (side);
	}
}

void	draw(double perpWallDist, int worldMap[mapWidth][mapHeight])
{
	// Calculate height of line to draw
	int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

	// calculate the lowes and highest pixel to fill in current stripe
	int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;
	
	// Choose wall color
	switch (worldMap[mapX][mapY])
	{
		case 1: color = 0x0c43c2d; break; // RED
		case 2: color = 0x041c42d; break; // GREEN
		case 3: color = 0x02f2dc4; break; // BLUE
		case 4: color = 0x0ffffff; break; // WHITE
		default: color = 0x0e5df87; break; // YELLOW
	}

	// Give x and y side a different brightness
	if (side == 1) 
		color = color / 2;
						
	draw_line(x, drawStart, x, drawEnd, mlx, win, color);
}

void	dda(t_raycast *ray, int **world_map)
{
	t_vector2	side_dist;
	t_vector2	delta_dist;
	double		perpWallDist;
	t_vector2	step;
	int			hit;
	int			side;
	int			mapX = (int)ray->pos.x;
	int			mapY = (int)ray->pos.y;

	delta_dist.x = sqrt(1 + (ray->dir.y * ray->dir.y) / (ray->dir.x * ray->dir.x));		
	delta_dist.y = sqrt(1 + (ray->dir.x * ray->dir.y) / (ray->dir.y * ray->dir.y));

	if (ray->dir.x < 0) 
	{
		step.x = -1;
		side_dist.x = (ray->pos.x - mapX);	
	}
	else
	{
		step.x = 1;
		side_dist.x = (mapX + 1.0 - ray->pos.x) * delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		step.y = -1;
		side_dist.y = (ray->pos.y - mapY) * delta_dist.y;	
	}
	else
	{
		step.y = 1;
		side_dist.y = (mapY + 1.0 - ray->pos.y) * delta_dist.y;
	}

	side = dda_loop(&side_dist, &delta_dist, &step, ray, world_map)

	if (side == 0)
		perpWallDist = (map.x - player.view.ray.pos.x + (1 - stepX) / 2) / rayDirX;
	else
		perpWallDist = (map.x - player.view.ray.pos.y + (1 - stepY) / 2) / rayDirY;
}
