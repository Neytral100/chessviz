#include <stdio.h>
#include "../h/coordinates.h"
#include "../h/move.h"

void move (struct coordinates *coor, int *board)
{	
	int old_place;
	int new_place;

	old_place = *(board + (coor -> x_old_place) + (coor -> y_old_place  * 8));
	new_place = *(board + (coor -> x_new_place) + (coor -> y_new_place  * 8));

	if (old_place != 0) {
		if (old_place == 1) {
			if ((coor -> y_new_place == coor -> y_old_place - 1) && (coor -> x_old_place == coor -> x_new_place)) {
				action (coor, board);
			}
		}
		if (old_place == -1) {
			if ((coor -> y_new_place == coor -> y_old_place + 1) && (coor -> x_old_place == coor -> x_new_place)) {
				action (coor, board);
			}
		}
	}

}

void action (struct coordinates *coor, int *board) 
{
	*(board + (coor -> x_new_place) + (coor -> y_new_place * 8)) = *(board + (coor -> x_old_place) + (coor -> y_old_place * 8));
	*(board + (coor -> x_old_place) + (coor -> y_old_place * 8)) = 0;
}