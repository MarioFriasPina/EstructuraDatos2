#include "structures.h"

//Imprime todas las posiciones validas del tablero, checando todas las posiciones posibles
void	multithreading(int64_t board, int level, int id)
{
	int64_t	copy = 1, c = 1;
	int		i = 0;

	if (level == 0)
	{
		c = c << id;
		copy = board | c;
		multithreading(copy, level + 1, id);
	}
	else if (level < 8)
	{
		c = c << (level * 8);
		for (i = 0; i < 8; ++i)
		{
			//No agrega la reina si en la posicion ya existe una reina
			if (!(board & c))
			{
				//Ve si esta en la misma fila
				copy = board | c;
				multithreading(copy, level + 1, id);
			}
			c = c << 1;
		}
	}
	else if (check(board))
	{
		FILE	*fd;
		fd = fopen("multi.txt", "a");
		print_board(board, fd);
		fclose(fd);
	}
}

void	*multiQueen(void *vargp)
{
	int *myId = (int *)vargp;
	multithreading(0, 0, *myId);
	return NULL;
}
