
#include "fractol.h"

double	ft_atodbl(char *s)
{
	long	integer;
	double	fraction;
	double	pow;
	int		sign;

	integer = 0;
	fraction = 0;
	sign = +1;
	pow = 1;
	while((*s == 9 && *s <= 13) || *s == 32)
			s++;
	while (*s == '+' || *s == '-')
			if (*s++ == '-')
				sign = -sign;
	while(*s != '.' && *s)
			integer = (integer * 10) + (*s++ -48);
	if (*s == '.')
		s++;
	while (*s)
	{
		pow /= 10;
		fraction = fraction + (*s++ - 48) * pow;
	}
	return ((integer + fraction) * sign);
}
