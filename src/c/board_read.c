#include <stdio.h>
#include <stdlib.h>
#include "../h/board_read.h"
#include "../h/coordinates.h"

struct coordinates * board_read ()
{
	struct coordinates *coor;
	coor = malloc (sizeof (struct coordinates));

	coor -> x_old_place = -1;
	coor -> y_old_place = -1;
	coor -> x_new_place = -1;
	coor -> y_new_place = -1;

	int i = 0;
	char string [6];
	for (i = 0; i < 6; i++) {
		string [i] = getchar ();
	}

	printf ("\n");
	for (i = 0; i < 6; i++) {
		printf ("%c", string[i]);
	}
	printf ("\n");


	char c;
	i = 0;
	for (c = 'a'; c <= 'h'; c++) {
		if (string [0] == c) {
			coor -> x_old_place = i;
		}
		if (string [3] == c) {
			coor -> x_new_place = i;
		}
		i++;
	}

	i = 7;
	for (c = '1'; c <= '8'; c++) {
		if (string [1] == c) {
			coor -> y_old_place = i;
		}
		if (string [4] == c) {
			coor -> y_new_place = i;
		}
		i--;
	}

	if ((coor -> x_old_place < 0) || (coor -> y_old_place < 0) || (coor -> x_new_place < 0) || (coor -> y_new_place < 0)) {
		printf ("Error input\n");
	}
	return coor;
}