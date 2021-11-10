#include "libft.h"

char    *ft_strjoin_free(char const *s1, char const *s2)
{
        char    *result;
        int             i;
        int             j;

        if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(s1)
                + ft_strlen(s2) + 1))))
                return (NULL);
        i = 0;
        j = 0;
        while (s1[j])
        {
                result[i] = s1[j];
                i++;
                j++;
        }
        j = 0;
        while (s2[j])
        {
                result[i] = s2[j];
                i++;
                j++;
        }
        result[i] = '\0';
        free((char *)s1);
        return (result);
}
