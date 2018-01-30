#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

#define serialize(x) #x

int my_strlen(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return(0);
	while (str[i])
		i++;
	return (i);
}

void my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

void my_putchar(char c)
{
	write(1, &c, 1);
}

void concat(char *str, char *src)
{
	int i;
	int len;

	i = 0;
	len = my_strlen(str);
	while (src[i]){
		str[i + len] = src[i];
		i++;
	}
}

void other_func(t_param arg)
{
	char *str;

	str = malloc(55);
	strcpy(str, "hello ");
	arg.callback(str, arg.param);
	init_ptr_and_call(str, &func, &my_putstr);
}

void func(t_param arg)
{
	char *str = (char *)arg.param;
	arg.callback(str);
}

int main(void)
{
	init_ptr_and_call("hello\n", &func, &my_putstr);
	init_ptr_and_call("world\n", &other_func, &concat);
}