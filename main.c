#include "structures.h"
#define THREADS 8

//Imprime el estado actual del tablero a la consola
void    print_board(int64_t board, FILE *fd)
{
	int64_t c = 1;
	char    i = 0;
	
	fprintf(fd, "---------------------------------\n");
	for (i = 0; i < 64; i++)
	{
		if (board & c)
			fprintf(fd, "| %sQ%s ", GRN, END);
		else
			fprintf(fd, "|   ");
		if (i % 8 == 7)
			fprintf(fd, "|\n---------------------------------\n");
		c = c << 1;
	}
	fprintf(fd, "\n");
}

int		main(void)
{
	int			i;
	int			id[THREADS];
	pthread_t	tid;
	clock_t		begin, end;

	remove("multi.txt");
	begin = clock();
	for(i = 0; i < THREADS; ++i)
	{
		id[i] = i;
		pthread_create(&tid, NULL, multiQueen, (void *)&id[i]);
	}

	end = clock();
	printf("%sMultithreaded = %f seconds\n%s", CYN, (double)(end-begin) / CLOCKS_PER_SEC, END);

	remove("brute.txt");
	begin = clock();

	brute_force(0, 0);
	
	end = clock();
	printf("%sBrute Force = %f seconds\n%s", MAG, (double)(end-begin) / CLOCKS_PER_SEC, END);
	return 0;
}
