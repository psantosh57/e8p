/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: e8p.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has e8p class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "e8p.h"

int e8p::get_num_moves() const {

	return 0;
}

string e8p::get_solution() const {

	return " ";
}


int e8p::hash::getKeyForBoard(board b) {

	int sum = 0;

	for (int i = 0; i < N; ++i) {

		for (int j = 0; j < N; ++j) {

			sum += ((i*N) + j) * b._n._matrix[i][j];
		}
	}

	return sum;
}

//EOF

