// This software is in the public domain.

#include <stdio.h>
#include "math.h"

typedef struct color {
	int r, g, b;
}Color;

Color
rainbow(int n)
{
	Color color;

	color.r = sin(0.1 * ((double) n) + 0) * 127 + 128;
	color.g = sin(0.1 * ((double) n) + 2 * M_PI / 3) * 127 + 128;
	color.b = sin(0.1 * ((double) n) + 4 * M_PI / 3) * 127 + 128;

	return color;
}

int
main(int argc, char *argv[])
{
	char input;
	unsigned int i = 0;
	Color color;

	while ((input = getchar()) != EOF) {
		color = rainbow(i);
		printf("\033[38;2;%d;%d;%dm%c\033[0m", color.r, color.g, color.b, input);
		i++;
	}
	return 0;
}
