#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

unsigned long factorielle(long n)
{
	if (n < 0)
	{
		exit(EXIT_FAILURE);
	}

	if (n == 0 || n == 1)
	{
		return 1L;
	}

	return n*factorielle(n-1);
}

unsigned long factorielle_terminale(long n, long result)
{
	if (n < 0 || result < 0)
	{
		exit(EXIT_FAILURE);
	}

	if (n == 1)
	{
		return result;
	}

	else if (n == 0)
	{
		return 1L;
	}

	return factorielle_terminale(n-1, n * result);
}

int main(int argc, char **argv){

	clock_t tic = clock();
	printf("%ld\n",factorielle(atoi(argv[1])));
	clock_t toc = clock();
    printf("factorielle: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

	clock_t tic1 = clock();
	printf("%ld\n",factorielle_terminale(atoi(argv[1]),1));
	clock_t toc1 = clock();
    printf("factorielle terminale: %f seconds\n", (double)(toc1 - tic1) / CLOCKS_PER_SEC);

	return 0;
}
