#include "libft.h"

char	*ft_get_file_name(const char *file_path)
{
	char	*file_name;
	char	*last_slash;

	last_slash = ft_strrchr(file_path, '/');
	if (!last_slash)
	{
		file_name = malloc(ft_strlen(file_path) + 1);
		ft_strlcpy(file_name, file_path, ft_strlen(file_path));
	}
	else
	{
		file_name = malloc(ft_strlen(last_slash) + 1);
		ft_strlcpy(file_name, last_slash + 1, ft_strlen(last_slash) + 1);
	}
	return (file_name);
}