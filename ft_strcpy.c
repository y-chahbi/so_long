#include "so_long.h"

void	*ft_strcpy(char *dst, char *src)
{
	size_t	dex;
	int n;

	dex = 0;
	if(!src)
		return (NULL);
	n = str_len(src);
	while (dex < n)
	{
		dst[dex] = src[dex];
		dex++;
	}
	free(src);
	return (dst);
}
