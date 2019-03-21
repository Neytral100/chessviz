/*
	  a b c d e f g h
	1 R N B Q K B N R 7
	2 P P P P P P P P 15
	3                 23
	4                 31
	5                 39
	6                 47
	7 p p p p p p p p 55
	8 r n b q k b n r 63
	
	     a  b  c  d  e  f  g  h

	1   -2 -3 -4 -5 -6 -4 -3 -2

	2   -1 -1 -1 -1 -1 -1 -1 -1

	3

	4

	5

	6

	7    1  1  1  1  1  1  1  1 

	8    2  3  4  5  6  4  3  2 
*/

#include <stdio.h>
#include "../h/board_output.h"

void board_output (int *board)
{
	FILE *pFileBoard = fopen ("../results/Сhessboard.txt", "w");
	if (pFileBoard == NULL) {
		printf ("Error with open the file");
		return;
	}
	int i;
	int j = 8;
	for (i = 1; i <= 64; i++) {
		fprintf(pFileBoard, "%c ", interpret (board + i - 1));
		if ((i % 8) == 0) {
			fprintf (pFileBoard, "%d ", j);
			j--;
		}
		if ((i % 8) == 0) {
			fprintf (pFileBoard, "\n");
		}
	}
	char c;
	for (c = 'a'; c <= 'h' ; c++) {
		fprintf(pFileBoard, "%c ", c);
	}
	fprintf (pFileBoard, "\n");

	fclose(pFileBoard);
}

char interpret (int *x)
{
	switch (*x) {
		case 1:
			return 'p';
			break;
		case 2:
			return 'r';
			break;
		case 3:
			return 'n';
			break;
		case 4:
			return 'b';
			break;
		case 5:
			return 'q';
			break;
		case 6:
			return 'k';
			break;
		case -1:
			return 'P';
			break;
		case -2:
			return 'R';
			break;
		case -3:
			return 'N';
			break;
		case -4:
			return 'B';
			break;
		case -5:
			return 'Q';
			break;
		case -6:
			return 'K';
			break;
		case 0:
			return ' ';
			break;
	}
	return '\0';
}