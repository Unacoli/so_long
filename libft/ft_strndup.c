#include "libft.h"

char    *ft_strndup(const char *src, size_t n)
{
        char    *ptr;
        size_t  i;

        i = 0;
        ptr = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
        if (ptr == 0)
                return (NULL);
        while (src[i] && i < n)
        {
                ptr[i] = src[i];
                i++;
        }
        ptr[i] = '\0';
        return (ptr);
}
