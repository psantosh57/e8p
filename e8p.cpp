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

e8p::e8p(const int s[N][N], const int f[N][N]) : _start(s), _finish(f), _numMoves(0), _solution("") {

	unordered_set <board, hash> uset;

	uset.insert(_start);


}

int e8p::get_num_moves() const {

	return 0;
}

string e8p::get_solution() const {

	return " ";
}

#if 0

int e8p::hash::getKeyForBoard(board b) {

	int sum = 0;

	for (int i = 0; i < N; ++i) {

		for (int j = 0; j < N; ++j) {

			sum += ((i*N) + j) * b._n._matrix[i][j];
		}
	}

	return sum;
}
#endif // 0


//EOF

