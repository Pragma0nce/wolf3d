/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:13:22 by kcoetzee          #+#    #+#             */
/*   Updated: 2017/07/12 15:01:20 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <string.h>
//#include <vector.h>
//#include <iostream.h>
#include <stdlib.h>
#include "mlx.h"
//place the example code below here:

#define mapWidth 24
#define mapHeight 24
#define	SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

int sign(x)
{
if(x>0)
 return 1;
else if(x<0)
 return -1;
else
 return 0;
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

int main(int argc, char **argv)
{
  	double posX = 22, posY = 12;  //x and y start position
  	double dirX = -1, dirY = 0; //initial direction vector
  	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

  	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame

  	void *mlx;
	void *win;
	//screen(512, 384, 0, "Raycaster");
  
	mlx = mlx_init();
	win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "mlx");

	while(!done())
  	{
    	for(int x = 0; x < w; x++)
    	{
      		//calculate ray position and direction
      		double cameraX = 2 * x / double(w) - 1; //x-coordinate in camera space
      		double rayPosX = posX;
      		double rayPosY = posY;
      		double rayDirX = dirX + planeX * cameraX;
      		double rayDirY = dirY + planeY * cameraX;
      		//which box of the map we're in
      		int mapX = int(rayPosX);
      		int mapY = int(rayPosY);

      		//length of ray from current position to next x or y-side
      		double sideDistX;
      		double sideDistY;

       		//length of ray from one x or y-side to next x or y-side
      		double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
      		double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
      		double perpWallDist;

      		//what direction to step in x or y-direction (either +1 or -1)
      		int stepX;
      		int stepY;ggt

      		int hit = 0; //was there a wall hit?
      		int side; //was a NS or a EW wall hit?
      	//calculate step and initial sideDist
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
      	//perform DDA
     	while (hit == 0)
      	{
        	//jump to next map square, OR in x-direction, OR in y-direction
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
        	//Check if ray has hit a wall
        	if (worldMap[mapX][mapY] > 0) hit = 1;
      	}
      	//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
      	if (side == 0) perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
      	else           perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;

      	//Calculate height of line to draw on screen
      	int lineHeight = (int)(h / perpWallDist);

      	//calculate lowest and highest pixel to fill in current stripe
      	int drawStart = -lineHeight / 2 + h / 2;
      	if(drawStart < 0)drawStart = 0;
      	int drawEnd = lineHeight / 2 + h / 2;
      	if(drawEnd >= h)drawEnd = h - 1;

      	//choose wall color
      	ColorRGB color;
      	switch(worldMap[mapX][mapY])
      	{
        	case 1:  color = RGB_Red;  break; //red
        	case 2:  color = RGB_Green;  break; //green
        	case 3:  color = RGB_Blue;   break; //blue
        	case 4:  color = RGB_White;  break; //white
        	default: color = RGB_Yellow; break; //yellow
      	}

      //give x and y sides different brightness
      	if (side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line
      	//verLine(x, drawStart, drawEnd, color);
        draw_line(x , drawStart, x, drawEnd, void *mlx, void *win, color)
}
    //timing for input and FPS counter
	oldTime = time;
    time = getTicks();
    double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    print(1.0 / frameTime); //FPS counter
    //redraw();
    //cls();
	/*
    //speed modifiers
    double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
    readKeys();
    //move forward if no wall in front of you
    if (keyDown(SDLK_UP))
    {
      if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
    }
    //move backwards if no wall behind you
    if (keyDown(SDLK_DOWN))
    {
      if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
    }
    //rotate to the right
    if (keyDown(SDLK_RIGHT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
      dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
    //rotate to the left
    if (keyDown(SDLK_LEFT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }V*/
  }
}
