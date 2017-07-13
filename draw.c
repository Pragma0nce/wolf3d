/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:30:14 by kcoetzee          #+#    #+#             */
/*   Updated: 2017/07/13 16:41:55 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	mlx_pixel_put(mlx, win, x2, y2, color);
}
