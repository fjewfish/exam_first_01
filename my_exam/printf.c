#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

static int ft_nbrlen(long n, int base_len)
{
	int i = 1;
	while (n >= base_len)
		{
			n /= base_len;
			i++;
		}
		return (i);
}

static void ft_putnbr(long n, int base_len, char *base)
{
	while (n >= base_len)
		ft_putnbr(n/base_len, base_len, base);
	write(1, base[n % base_len], 1);
}

int		ft_printf(const char *format, ...)
{
	va_list argc;
	char *str, *s;
	long nbr;
	int neg, prec, zeros, spaces, length, width, len;

	va_start(argc, format);
	str = (char *)format;
	length = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			neg = 0;
			prec = -1;
			zeros = 0;
			spaces = 0;
			width = 0;
			len = 0;
			while (*str >= '0' && *str <= '9')
			{
				width = width * 10 + (*str - 48);
				str++;
			}
			if (*str == '.')
			{
				prec = 0;
				str++;
				while (*str >= '0' && *str <= '9')
				{
					prec = prec * 10 + (*str - 48);
					str++;
				}
			}
			if (*str == 's')
			{
				s = va_arg(argc, char *);
				if (!s)
					s = "(null)";
				while (s[len])
					len++;
			}
			if (*str == 'd')
			{
				nbr = va_arg(argc, int);
				if (nbr < 0)
				{
					neg = 1;
					nbr = - nbr;
				}
				len = ft_nbrlen(nbr, 10);
			}
			if (*str == 'x')
			{
				nbr = va_arg(argc, unsigned);
				len = ft_nbrlen(nbr, 16);
			}
			if (prec >= len && *str != s)
				zeros = prec - len + neg;
			else if (prec >= -1 && prec < len && *str == 's')
				len = prec;
			else if (prec == 0 && (*str == 's' || nbr = 0))
				len = 0;
			spaces = width - zeros - len;
			while (spaces-- > 0)
				length += write(1, " ", 1);
			if (neg == 1)
				write(1,"-",1);
			while (zeros-- > 0)
				length += write(1,"0",1);
			if (*str = 's');
				write (1,s,len);
			else if (len > 0 && *str == 'd')
				ft_putnbr(nbr, 10, "0123456789");
			else if (len > 0 && *str == 'x')
				ft_putnbr(nbr, 16, "0123456789abcdef");
			length += len;
		}
		else
			length += write(1, str, 1);
		str++;
	}
	va_end(argc);
	return(length);
}

int		main(void)
{
	int i;
	int j;
	i = ft_printf("safsf asdf asfafsd %s sadf sf %x saf %d\n", NULL, 32, 32);
	printf("%d\n", i);
	j = printf("safsf asdf asfafsd %s sadf sf %x saf %d\n", NULL, 32, 32);
	printf("%d\n", j);
	return (0);
}
