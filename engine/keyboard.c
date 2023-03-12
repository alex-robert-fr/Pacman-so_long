#include "../includes/pacman.h"

int	keyboard(int keycode, t_entity *player)
{
	if (keycode == 65361)
	{
		ft_putstr_fd("LEFT\n",1);
		player->next_direction.x = -1;
		player->next_direction.y = 0;
	}
	if (keycode == 65362)
	{
		ft_putstr_fd("UP\n",1);
		player->next_direction.x = 0;
		player->next_direction.y = -1;
	}
	if (keycode == 65363)
	{
		ft_putstr_fd("RIGHT\n",1);
		player->next_direction.x = 1;
		player->next_direction.y = 0;
	}
	if (keycode == 65364)
	{
		ft_putstr_fd("DOWN\n",1);
		player->next_direction.x = 0;
		player->next_direction.y = 1;
		ft_putstr_fd("POS X: ",1);
		ft_putnbr_fd(player->position.x / 24,1);
		ft_putstr_fd(", POS Y: ",1);
		ft_putnbr_fd(player->position.y / 24,1);
		ft_putstr_fd("\n",1);
	}
}