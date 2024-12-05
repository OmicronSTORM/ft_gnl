#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int	fd;
	char *str;
	int	rd;

	str = malloc(sizeof(char) * 4 + 1);
	fd = open("test.txt", O_RDONLY);
	rd = read(fd, str, 4);
	printf("%d : %s -> adresse : %p || %d\n", fd, str, &str, rd);
	free(str);
	str = malloc(sizeof(char) * 4 + 1);
	rd = read(fd, str, 4);
	printf("%d : %s -> adresse : %p || %d\n", fd, str, &str, rd);
	str[2] = '\0';
	free(str);
	close(fd);
	return (0);
}