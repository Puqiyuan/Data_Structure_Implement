// timer1.cpp
// This program computing the time consumption of this program.

#include <stdio.h>
#include <sys/timeb.h>

int main(int argc, char *argv[])
{
	timeb start, end;
	long t;
	double x, sum = 1, sum1;
	int i, j, n;
	printf("Please input x n:");
	scanf("%lf%d", &x, &n);

	ftime(&start);
	for (i = 1; i <= n; i++)
		{
			sum1 = 1;
			for (j = 1; j <= i; j++)
				sum1 = sum1 * (-1.0 / x);
			sum += sum1;
		}
	ftime(&end);

	t = (end.time - start.time) * 1000 + (end.millitm - start.millitm);

	printf("sum = %lf time consumption %ld ms.\n", sum, t);
	
	return 0;
}

