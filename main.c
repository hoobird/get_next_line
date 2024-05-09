// #include "get_next_line.a"
#include  <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int file = open("test.txt", O_RDONLY);
	char * s = get_next_line(file);
	printf("%s", s);
	free(s);
	s = get_next_line(file);
	printf("%s", s);
	free(s);
	s = get_next_line(file);
	printf("%s", s);
	free(s);
	// s = get_next_line(file);
	// printf("%s", s);
	// free(s);
	return (0);
}