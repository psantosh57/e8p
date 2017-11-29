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
int node::_count = 0;
static int k = 0;

e8p::e8p(const int s[N][N], const int f[N][N]) : _start(s), _finish(f), _numMoves(0), _solution(""), _foundSolution(false) {

	if (_start != _finish) {

		int row = 0;
		int col = 0;
		findSpaceAndPopulate(_start, row, col);

		while (!queue.empty()) {

			board* temp = queue.front();
			queue.pop();

			_numMoves++;

			if (*temp == _finish) {

				_solution = temp->_string;

				break;
			}
			else {
				findSpaceAndPopulate(*temp, row, col);
			}

		}

	}

}

int e8p::get_num_moves() const {

	return _numMoves;
}

string e8p::get_solution() const {

	return _solution;
}

void e8p::popoulateKids(board& b, int r, int c) {

	if (r == 0) {
		
		swapDown(b, r, c);

	} 
	else if (r == 1) {

		swapDown(b, r, c);
		swapUp(b, r, c);

	}
	else if (r == 2) {

		swapUp(b, r, c);

	}

	if (c == 0) {

		swapRight(b, r, c);

	}
	else if (c == 1) {

		swapRight(b, r, c);
		swapLeft(b, r, c);
		
	}
	else if (c == 2) {

		swapLeft(b, r, c);
		
	}

}

void e8p::swapDown(board& b, int r, int c) {

	board* _down = b.createBoard();

	int temp = _down->_n._matrix[r][c];
	_down->_n._matrix[r][c] = _down->_n._matrix[r + 1][c];
	_down->_n._matrix[r + 1][c] = temp;
	_down->_string = b._string + "D";

	unordered_set<board*, board::Hash, board::Compare>::const_iterator got = uset.find(_down);
	if (got == uset.end()) {

		queue.push(_down);
		uset.insert(_down);

	}
	else {

		delete _down;
	}

}


void e8p::swapUp(board& b, int r, int c) {

	board* _up = b.createBoard();

	int temp = _up->_n._matrix[r][c];
	_up->_n._matrix[r][c] = _up->_n._matrix[r - 1][c];
	_up->_n._matrix[r - 1][c] = temp;
	_up->_string = b._string + "U";

	unordered_set<board*, board::Hash, board::Compare>::const_iterator got = uset.find(_up);
	if (got == uset.end()) {

		queue.push(_up);
		uset.insert(_up);

	}
	else {

		delete _up;
	}

}

void e8p::swapLeft(board& b, int r, int c) {

	board* _left = b.createBoard();

	int temp = _left->_n._matrix[r][c];
	_left->_n._matrix[r][c] = _left->_n._matrix[r][c - 1];
	_left->_n._matrix[r][c - 1] = temp;
	_left->_string = b._string + "L";

	unordered_set<board*, board::Hash, board::Compare>::const_iterator got = uset.find(_left);
	if (got == uset.end()) {

		queue.push(_left);
		uset.insert(_left);

	}
	else {

		delete _left;
	}

}

void e8p::swapRight(board& b, int r, int c) {

	board* _right = b.createBoard();

	int temp = _right->_n._matrix[r][c];
	_right->_n._matrix[r][c] = _right->_n._matrix[r][c + 1];
	_right->_n._matrix[r][c + 1] = temp;
	_right->_string = b._string + "R";

	unordered_set<board*, board::Hash, board::Compare>::const_iterator got = uset.find(_right);
	if (got == uset.end()) {

		queue.push(_right);
		uset.insert(_right);

	}
	else {

		delete _right;
	}

}

void e8p::findSpaceAndPopulate(board& b, int& row, int& col) {

	for (int i = 0; i < N; ++i) {

		for (int j = 0; j < N; ++j) {

			if (b._n._matrix[i][j] == 0) {

				row = i;
				col = j;
				break;
			}
		}
	}

	popoulateKids(b, row, col);

}

board* board::createBoard() {

	board* temp = new board(_n._matrix);

	return temp;
}

//EOF

