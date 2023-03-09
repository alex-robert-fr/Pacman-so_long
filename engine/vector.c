#include "../includes/pacman.h"

t_vector	v_zero()
{
	t_vector	vector;

	vector.x = 0;
	vector.y = 0;
	return (vector);
}

t_vector	v_init(int x, int y)
{
	t_vector	vector;
	
	vector.x = x;
	vector.y = y;
	return (vector);
}