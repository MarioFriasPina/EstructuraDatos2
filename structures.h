#ifndef STRUCTURES_H
# define STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define END	"\x1B[0m"

//Brute_Force
int		check(int64_t board);
void	brute_force(int64_t board, int level);

//Multithreading
void	multithreading(int64_t board, int level, int id);
void	*multiQueen(void *vargp);

//Main
void	print_board(int64_t board, FILE *fd);

#endif
