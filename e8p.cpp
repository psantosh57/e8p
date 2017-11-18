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

e8p::e8p(const int s[N][N], const int f[N][N]) : _start(s), _finish(f), _numMoves(0), _solution(""), _foundSolution(false) {

	unordered_set <board, hash> uset;
	queue<board> queue;

	//Push the first board in hash 
	uset.insert(_start);
	queue.push(_start);

	unordered_set<board, hash>::const_iterator got = uset.find(_start);

	while (!queue.empty) {

		board temp = queue.front();

		if (temp == _finish) {

			_foundSolution = true;
			break;

		}
		else {

			pushCombos 

		}

	}



}

int e8p::get_num_moves() const {

	return 0;
}

string e8p::get_solution() const {

	return " ";
}

void e8p::pushCombos(queue<board> & q, board& b) {

	int row = 0;
	int column = 0;
	findSpace(b, row, column);

	if (row == 1) {

		b._down = swap(b, row, column, "down");
	}

}

void e8p::findSpace(board& b, int& row, int& column) {

	for (int i = 0; i < N; ++i) {

		for (int j = 0; j < N; ++j) {

			if (b._n._matrix[i][j] == 0) {

				row = i;
				column = j;
				break;
			}
		}
	}

}

board* e8p::swap(board& b, int r, int c, const char* str) {


}

//EOF

