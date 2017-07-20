/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 10:49:03 by kcoetzee          #+#    #+#             */
/*   Updated: 2017/07/17 11:25:18 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"



int main()
{
	void *mlx;
	void *win;
	int color;
	int i;
	i = 0;
	// mlx init
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
	double perpWallDist;
	int side;
	t_vector2i map;

	while (!done)
	{
		// Ray casting loop
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			update_view(&player, x);	
			dda(&player.view.ray, int **world_map)
			mlx_key_hook(win, check_input, 0); 
		}
		mlx_loop(mlx);
	}	
}

















