/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 11:30:22 by kcoetzee          #+#    #+#             */
/*   Updated: 2017/07/13 16:41:55 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int sign(x)
{
if(x>0)
 return 1;
else if(x<0)
 return -1;
else
 return 0;
}

int check_input(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	
	return(0);	
}



void	update_view(Player *player)
{
	player->view.pos.x = 2 * x / (double) SCREEN_WIDTH - 1;
	player->view.ray.pos.x = player->pos.x;
	player->view.ray.pos.x = player->pos.y;
	player->view.ray.dir.x = player->dir.x + player->view.plane.x * player->view.x;
	player->view.ray.dir.y = player->dir.y + player->view.plane.y * player->view.x;
}


int main()
{
	void *mlx;
	void *win;
	int color;
	int i;
	int worldMap[mapWidth][mapHeight]=
	{
  		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	i = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "mlx");
	
	// Player init
	t_player player;
	player.pos.x = 22;
	player.pos.y = 12;
	player.view.plane.x = 0;
	player.view.plane.y = 0.66;
	
	int done = 0;
	double time = 0;
	double oldTime = 0;
	double perpWallDist;
	int side;
	t_vector2i map;

	while (!done)
	{
		// Ray casting loop
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			side = dda(player.view.ray, worldMap);

			map.x = (int)ray->pos.x;
			map.y = (int)ray->pos.y;
			// Calculate distance projected on camera direction
			if (side == 0)
				perpWallDist = (map.x - rayPosX + (1 - stepX) / 2) / rayDirX;
			else
				perpWallDist = (map.x - rayPosY + (1 - stepY) / 2) / rayDirY;
			
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
						
			
			void *screen = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
			draw_line(x, drawStart, x, drawEnd, mlx, win, color);
			double moveSpeed = 5;
			double rotSpeed = 3;
			
			//posX += dirX * 0.02;
			mlx_key_hook(win, check_input, 0); 
		}
		mlx_loop(mlx);
	}	
}

















