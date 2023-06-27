#include <stdio.h>
int is_float(char *c)
{
	int i = 0;
	int decimal_pos = 0;
	int decimal_present = 0;
	while (c[i])
	{
		if (c[i] < '0' || c[i] > '9')
		{
			if (c[i] != '.')
				return (0);
		}
		i++;
	}
	i = 0;
	while ((c[i] >= '0' && c[i] <= '9') || c[i] == '.')
	{
		i++;
		if (c[i] == '.' && !decimal_present)
		{
			decimal_pos = i;
			decimal_present = 1;
		}
	}
	if (i > 8)
		return (0);
	return (decimal_pos);
}

float strict_atofloat(char *number)
{
	float	f = 0.0;
	int 	i = 0;
	int		lowpower = 0;
	if (is_float(number))
	{
		int decimal_pos = is_float(number);
		while (number[i])
			i++;
		lowpower = i - decimal_pos;
		i = 0;
		while (number[i])
		{
			if (number[i] == '.')
				i++;
			f = f + (number[i] - 48);
			f *= 10;
			i++;
		}
		while (lowpower)
		{
			f *= 0.1;
			lowpower--;
		}
	}
	else
		return (0);
	return (f);
}

void	repeat(int *c)
{
	*c += 1;
	int l = 1;
	float x = strict_atofloat("42.0");
	printf("Entering While Loop #%d\n", *c);
	while (l)
	{
		printf("Loop Iteration #%d\n", l);
		repeat(c);
		l++;
	}
}

int	main(void)
{
	int c = 42;
	repeat(&c);
	
	return (0);
}