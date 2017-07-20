#include "main.h"

void	update_view(t_player *player, int x)
{
	player->view.pos.x = 2 * x / (double) SCREEN_WIDTH - 1;
	player->view.ray.pos.x = player->pos.x;
	player->view.ray.pos.y = player->pos.y;
	player->view.ray.dir.x = player->dir.x + player->view.plane.x * player->view.x;
	player->view.ray.dir.y = player->dir.y + player->view.plane.y * player->view.x;
}

int		choose_wall_color(int map[MAP_WIDTH][MAP_HEIGHT], int map_x, int map_y)
{
	int	color;

	switch (map[map_x][map_y])
	{
		case 1: color = 0x0c43c2d; break; // RED
		case 2: color = 0x041c42d; break; // GREEN
		case 3: color = 0x02f2dc4; break; // BLUE
		case 4: color = 0x0ffffff; break; // WHITE
		default: color = 0x0e5df87; break; // YELLOW
	}
	return (color);
}

void	dda_loop()
{

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

void	dda()
{

	//length of ray from current position to next x or y-side
    double sideDistX;
    double sideDistY;

       		//length of ray from one x or y-side to next x or y-side
    double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
    double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
    double perpWallDist;

	//what direction to step in x or y-direction (either +1 or -1)
	int stepX;
    int stepY;

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
	dda_loop();
	//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
    if (side == 0) perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
    else           perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;
	
    //Calculate height of line to draw on screen
    int lineHeight = (int)(h / perpWallDist);
}

void	draw_walls(int lineHeight)
{
	//calculate lowest and highest pixel to fill in current stripe
    int drawStart = -lineHeight / 2 + h / 2;
    if(drawStart < 0)drawStart = 0;
    int drawEnd = lineHeight / 2 + h / 2;
    if(drawEnd >= h)drawEnd = h - 1;

    //choose wall color
	color = choose_wall_color(map, mapX, mapY);
	//give x and y sides different brightness
    if (side == 1) {color = color / 2;}

	//draw the pixels of the stripe as a vertical line
    draw_line(x , drawStart, x, drawEnd, void *mlx, void *win, color);
}

void	raycast(t_player *player, int map[MAP_WIDTH][MAP_HEIGHT])
{
	int lineHeight;

    for(int x = 0; x < w; x++)
    {
      	//calculate ray position and direction
      	update_view(player, x);
		//which box of the map we're in
      	int mapX = int(rayPosX);
      	int mapY = int(rayPosY);
		// dda algorithm
      	lineHeight = dda();
		// rendering
		draw_walls(lineHeight);
	}
}
