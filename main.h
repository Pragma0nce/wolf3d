#ifndef	MAIN_H
# define MAIN_H

typedef	struct	s_vector2
{
	double	x;
	double	y;
}				t_vector

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
