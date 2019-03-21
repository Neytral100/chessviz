#include <stdio.h>
#include <stdlib.h>
#include "../h/board_init.h"
#include "../h/board_output.h"
#include "../h/board_read.h"
#include "../h/coordinates.h"
#include "../h/move.h"

int main ()
{	
	int *board;
	struct coordinates *coor; 
	board = board_init ();
	board_output(board);
	coor = board_read ();
	move (coor, board);
	board_output(board);
	coor = board_read ();
	move (coor, board);
	board_output(board);
	return 0;
}