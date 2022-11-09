#include "structures.h"

//Checa si la posicion actual es valida
int		check(int64_t board)
{
	int64_t	checker = 1, temp = 1;
	int		i = 0, j = 0;

	for (i = 0; i < 64; i++)
	{
		//Existe una reina en la posicion actual
		if (checker & board)
		{		
			//Horizontal
			for (j = 1; j <= (7 - (i % 8)); j++)
			{
				temp = checker << j;
				if (temp & board)
					return (0);
				//Diagonal derecho inferior
				temp = checker << (j * 9);
				if (temp & board)
					return (0);

			}
			//Vertical
			for (j = 1; j <= (7 - (i / 8)); j++)
			{
				temp = checker << (j * 8);
				if (temp & board)
					return (0);
			}
			//Diagonal izquierdo inferior
			for (j = 1; j <= (i % 8); j++)
			{
				temp = checker << (j * 7);
				if (temp & board)
					return (0);
			}
		}
		checker = checker << 1;
	}
	return (1);
}

//Imprime todas las posiciones validas del tablero, checando todas las posiciones posibles
void	brute_force(int64_t board, int level)
{
	int64_t	copy = 1, c = 1;
	int		i = 0;

	if (level < 8)
	{
		c = c << (level * 8);
		for (i = 0; i < 8; i++)
		{
			//No agrega la reina si en la posicion ya existe una reina
			if (!(board & c))
			{
				//Ve si esta en la misma fila
				copy = board | c;
				brute_force(copy, level + 1);
			}
			c = c << 1;
		}
	}
	else if (check(board))
	{
		FILE	*fd;
		fd = fopen("brute.txt", "a");
		print_board(board, fd);
		fclose(fd);
	}
}
