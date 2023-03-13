#include "../includes/pacman.h"

void *choise_direction_ia(t_map map, t_entity *entity)
{
	// printf("PACMAN\n");
	int num;
	void *check;

	check = 0;
	while (!check)
	{
		num = (rand() % (3 - 0 + 1)) + 0;
		if (!num)
		{
			// ft_putstr_fd("LEFT\n",1);
			entity->next_direction.x = -1;
			entity->next_direction.y = 0;
		}
		if (num == 1)
		{
			// ft_putstr_fd("UP\n",1);
			entity->next_direction.x = 0;
			entity->next_direction.y = -1;
		}
		if (num == 2)
		{
			// ft_putstr_fd("RIGHT\n",1);
			entity->next_direction.x = 1;
			entity->next_direction.y = 0;
		}
		if (num == 3)
		{
			// ft_putstr_fd("DOWN\n",1);
			entity->next_direction.x = 0;
			entity->next_direction.y = 1;
		}
		if (!check_direction(map, entity))
			check = 0;
		else
			check = 1;
	}

}