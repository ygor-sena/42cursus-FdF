#include <stdint.h>
#include <stdio.h>

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

int	main(void)
{
	int	r;
	int	g;
	int	b;
	int	converted;

	r = 255;
	g = 255;
	b = 255;
	converted = encode_rgb(r, g, b);
	printf("Encoded color is: %d\n", converted);
	return (0);
}
