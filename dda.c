
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
}
