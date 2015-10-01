#include "stdlib.h"
#include "stdio.h"

void main()
{
	int x, y, z;
	z = 0;
	printf("x = ");
	scanf("%d", &x);
	printf("y = ");
	scanf("%d", &y);
	while(x > 1)
	{
		
		if(x % 2 == 0)
		{
			x = x / 2;
			y = y * 2;
		}
		else
		{
			x = x - 1;
			z = z + y;
		}
		printf("\n= %d * %d + %d", x, y, z);
	}
	x = y + z;
	printf("\n= %d", x);
}
