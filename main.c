#include "structures.h"

//Imprime el estado actual del tablero a la consola
void    print_board(int64_t board, FILE *fd)
{
	int64_t c = 1;
	char    i = 0;

	for (i = 0; i < 64; i++)
	{
		if (board & c)
			fprintf(fd, "Q");
		else
			fprintf(fd, "0");
		if (i % 8 == 7)
			fprintf(fd, "\n");
		c = c << 1;
	}
	fprintf(fd, "\n");
}

int		main(void)
{
	int			i;
	pthread_t	tid;
	clock_t		begin = clock(), end;

	for(i = 0; i < 9; i++)
		pthread_create(&tid, NULL, multiQueen, (void *)&i);

	end = clock();
	printf("Multithreaded = %f seconds\n", (double)(end-begin) / CLOCKS_PER_SEC);

	begin = clock();

	brute_force(0, 0);
	
	end = clock();
	printf("Brute Force = %f seconds\n", (double)(end-begin) / CLOCKS_PER_SEC);
	return 0;
}
