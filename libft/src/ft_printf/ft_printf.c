/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:59:11 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/11 21:43:02 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char specifier, va_list *ap)
{
	int	i;

	i = 0;
	if (specifier == 'c')
		i += ft_print_char(va_arg(*ap, int));
	else if (specifier == 's')
		i += ft_print_str(va_arg(*ap, char *));
	else if (specifier == 'p')
		i += ft_print_ptr(va_arg(*ap, unsigned long long));
	else if (specifier == 'u')
		i += ft_print_unsigned(va_arg(*ap, unsigned int));
	else if (specifier == 'd' || specifier == 'i')
		i += ft_print_digits((long)(va_arg(*ap, int)), 10);
	else if (specifier == 'x')
		i += ft_print_digits((long)(va_arg(*ap, unsigned int)), 16);
	else if (specifier == 'X')
		i += ft_print_upper_digits((long)(va_arg(*ap, unsigned int)), 16);
	else
		i += write (1, "%", 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return (len);
			len += ft_format(*format, &ap);
		}
		else
			len += ft_print_char(*format);
		format++;
	}
	va_end(ap);
	return (len);
}

/* int main()
{
	 */

/* 	ft_printf("%s", NULL);
 *//* 	printf("%d chars\n",  i);
	i = ft_printf("%c %c %c\n", '1', '2', '3');
	printf("%d chars\n",  i);
	i = ft_printf("%c %c %c\n", '2', '1', 0);
	printf("%d chars\n",  i);
	write (1, "\n", 1);
	i = printf("%c %c %c\n", '0', 0, '1');
	printf("%d chars\n",  i);
	i = printf("%c %c %c\n", '1', '2', '3');
	printf("%d chars\n",  i);
	i = printf("%c %c %c\n", '2', '1', 0);
	printf("%d chars\n",  i); */

	/* puts("My printf");
	 i = ft_printf("Hello %s\n", "Luis");
	printf("%d chars\n",  i);
	 i = ft_printf("Char-> %c\n", 'a');
	printf("%d chars\n",  i);
	 i =ft_printf("Nbr-> %d\n", -42);
	printf("%d chars\n",  i);
	 i = ft_printf("Hex-> %x\n", -1);
	printf("%d chars\n",  i);

	//REAL 
	printf("\n\n");
	puts("Real printf");
	 i = printf("Hello %s\n", "Luis");
	printf("%d chars\n",  i);
	 i = printf("Char-> %c\n", 'a');
	printf("%d chars\n",  i);
	 i = printf("Nbr-> %d\n", -42);
	printf("%d chars\n",  i);
	 i = printf("Hex-> %x\n", -1);
	printf("%d chars\n",  i); */
