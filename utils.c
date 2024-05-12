#include "fractol.h"

int ft_cmp(const char *s1, const char *s2) 
{
    if (!*s1 || !*s2)
    {
        return (0);
    }
    while (*s1 && *s2 && *s1 == *s2) 
    {
        s1++;
        s2++;
    }
    if(*s1 == '\0' && *s2 == '\0')
        return 0;
    else if(*s1 > *s2)
        return 1;
    else if(*s1 < *s2)
        return -1;
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}


float ft_atof(const char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}