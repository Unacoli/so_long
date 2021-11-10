#include "libft.h"

int             ft_free(void **ptr)
{
        free(*ptr);
        *ptr = NULL;
        return (0);
}
