// #include "get_next_line.a"
#include  <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int file = open("test.txt", O_RDONLY);
	int file2 = open("test2.txt", O_RDONLY);
	int file3 = open("test3.txt", O_RDONLY);
	char * s = get_next_line(file);
	printf("%s\n", s);
	free(s);
	s = get_next_line(file2);
	printf("%s\n", s);
	free(s);
	s = get_next_line(file3);
	printf("%s\n", s);
	free(s);
	s = get_next_line(file2);
	printf("%s\n", s);
	free(s);
	s = get_next_line(file);
	printf("%s\n", s);
	free(s);
	s = get_next_line(file3);
	printf("%s\n", s);
	free(s);
	s = get_next_line(file2);
	printf("%s\n", s);
	free(s);
	s = get_next_line(file);
	printf("%s\n", s);
	free(s);
	s = get_next_line(file);
	printf("%s\n", s);
	free(s);
	return (0);
}