/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 11:30:22 by kcoetzee          #+#    #+#             */
/*   Updated: 2017/07/12 15:01:18 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include<math.h>
#include <stdio.h>

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#define mapWidth 24
#define mapHeight 24

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

void draw_line(int x1,int y1, int x2, int y2, void *mlx, void *win, int color)
{
int x,y,dx,dy,swap,temp,s1,s2,p,i;

x=x1;
y=y1;
dx=abs(x2-x1);
dy=abs(y2-y1);
s1=sign(x2-x1);
s2=sign(y2-y1);
swap=0;
//putpixel(x1,y1,RED);
mlx_pixel_put(mlx, win, x1, y1, color);
if(dy>dx)
 {
 temp=dx;
 dx=dy;
 dy=temp;
 swap=1;
 }
p=2*dy-dx;
for(i=0;i<dx;i++)
 {
 //putpixel(x,y,getcolor());
 mlx_pixel_put(mlx, win, x, y, color);
while(p>=0)
  {
  p=p-2*dx;
  if(swap)
   x+=s1;
  else
   y+=s2;
  }
 p=p+2*dy;
 if(swap)
  y+=s2;
 else
  x+=s1;
 }
//putpixel(x2,y2,RED);
mlx_pixel_put(mlx, win, x2, y2, color);
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
	
	double posX = 22, posY = 12;
	double dirX = -1, dirY = 0;
	double planeX = 0, planeY = 0.66;
	int done = 0;
	double time = 0;
	double oldTime = 0;

	while (!done)
	{
		// Ray casting loop
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			double cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
			double rayPosX = posX;
			double rayPosY = posY;
			double rayDirX = dirX + planeX * cameraX;
			double rayDirY = dirY + planeY * cameraX;

			// Which box of the map
			int mapX = (int)rayPosX;
			int mapY = (int)rayPosY;

			// Length of the ray from current position to the next x or y side
			double sideDistX;
			double sideDistY;

			// Length of ray from one x or y-side to next x or y-side
			double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
			double deltaDistY = sqrt(1 +  (rayDirX * rayDirX) / (rayDirY * rayDirY));
			double perpWallDist;

			// What direction to step in
			int stepX;
			int stepY;
			int hit = 0; // Was a wall hi
			int side; // Which side of the wall was hit

			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (rayPosX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (rayPosY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
			}

			// Perform the DDA
			while (hit == 0)
			{
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				if (worldMap[mapX][mapY] > 0) hit = 1;
			}

			// Calculate distance projected on camera direction
			if (side == 0)
				perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
			else
				perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;
			
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
			mlx_put_image_to_window(mlx, win, screen, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
			mlx_destroy_image(mlx, screen);
			double moveSpeed = 5;
			double rotSpeed = 3;
			
			//posX += dirX * 0.02;
			mlx_key_hook(win, check_input, 0); 
		}
		mlx_loop(mlx);
	}	
}

















