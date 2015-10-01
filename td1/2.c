#include "stdlib.h"
#include "stdio.h"

void main()
{
	int t, h, min, s;
	scanf("%d", &t);
	printf("%d secondes sont", t);
	s = t % 60;
	t = t - s;
	h = t / 3600;
	min = (t - h * 3600) / 60;
	if(h == 1)
	{
		printf(" 1 heure");
	}
	else
	{
		printf(" %d heures", h);
	}
	if(min == 1)
	{
		printf("1 minute");
	}
	else
	{
		printf(" %d minutes", min);
	}
	if(s == 1)
	{
		printf(" 1 seconde");
	}
	else
	{
		printf(" %d secondes", s);
	}
}
