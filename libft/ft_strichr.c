#include "libft.h"

int             ft_strichr(const char *s, int c)
{
        int i;

        i = 0;
        if (c == 0)
        {
                while (s[i])
                        i++;
                return (i);
        }
        while (s[i])
        {
                if (s[i] == c)
                        return (i);
                i++;
        }
        return (i);
}
