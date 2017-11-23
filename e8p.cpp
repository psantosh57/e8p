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

	if (_start != _finish) {

		//unordered_set <board, board::hash> uset;
		//queue<board*> queue;
		//stack<board*> stack;

		//Push the first board in hash 
		_uset.insert(_start);
		//unordered_set<board, board::hash>::const_iterator got = uset.find(_start);

		int row = 0;
		int col = 0;
		findSpaceAndPopulate(_start, row, col);
		//pushInStack(_start, stack, uset);
		//pushInStack(_start, _queue, _uset);

		//fillQueue(

		cout << "Here" << endl;

		board* parent = &_start;
		_solution = _start._string;

#if 0
		while (!queue.empty()) {

			//board* temp = stack.top();
			//stack.pop();
			board* temp = _queue.front();
			_queue.pop();

			_numMoves++;


			if (*temp == _finish) {

				_solution = temp->_string;

				break;
			}
			else {
				findSpaceAndPopulate(*temp, row, col);
				//pushInStack(*temp, stack, uset);
				pushInStack(*temp, _queue, _uset);
			}

#if 0
			if (parent == temp->_parent) {

				_solution = temp->_string;
				parent = temp;

			}
			else {

				_solution = _solution + temp->_string;

		}
#endif // 0





	}
#endif // 0


		while (!_queue.empty()) {


			board temp = _queue.front();
			_queue.pop();

			_numMoves++;


			if (temp == _finish) {

				_solution = temp._string;

				break;
			}
			else {
				findSpaceAndPopulate(temp, row, col);
				//pushInStack(*temp, stack, uset);
				//pushInStack(*temp, _queue, _uset);
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

	board down = board(b);

	int temp = down._n._matrix[r][c];
	down._n._matrix[r][c] = down._n._matrix[r + 1][c];
	down._n._matrix[r + 1][c] = temp;
	down._string = b._string + "D";
	
	unordered_set<board, board::hash>::const_iterator got = _uset.find(down);
	if (got == _uset.end()) {

		_queue.push(down);
		_uset.insert(down);

	}

#if 0
	_down = createBoard();
	_down->_parent = this;

	int temp = _down->_n._matrix[r][c];
	_down->_n._matrix[r][c] = _down->_n._matrix[r + 1][c];
	_down->_n._matrix[r + 1][c] = temp;
	_down->_string = _string + "D";
#endif // 0


}

void e8p::swapUp(board& b, int r, int c) {

	board up = board(b);

	int temp = up._n._matrix[r][c];
	up._n._matrix[r][c] = up._n._matrix[r - 1][c];
	up._n._matrix[r - 1][c] = temp;
	up._string = b._string + "U";

	unordered_set<board, board::hash>::const_iterator got = _uset.find(up);
	if (got == _uset.end()) {

		_queue.push(up);
		_uset.insert(up);

	}

#if 0
	_up = createBoard();
	_up->_parent = this;

	int temp = _up->_n._matrix[r][c];
	_up->_n._matrix[r][c] = _up->_n._matrix[r - 1][c];
	_up->_n._matrix[r - 1][c] = temp;
	_up->_string = _string + "U";
#endif // 0


}

void e8p::swapLeft(board& b, int r, int c) {

	board left = board(b);

	int temp = left._n._matrix[r][c];
	left._n._matrix[r][c] = left._n._matrix[r][c - 1];
	left._n._matrix[r][c - 1] = temp;
	left._string = b._string + "L";

	unordered_set<board, board::hash>::const_iterator got = _uset.find(left);
	if (got == _uset.end()) {

		_queue.push(left);
		_uset.insert(left);

	}

#if 0
	_left = createBoard();
	_left->_parent = this;

	int temp = _left->_n._matrix[r][c];
	_left->_n._matrix[r][c] = _left->_n._matrix[r][c - 1];
	_left->_n._matrix[r][c - 1] = temp;
	_left->_string = _string + "L";
#endif // 0


}

void e8p::swapRight(board& b, int r, int c) {

	board right = board(b);

	int temp = right._n._matrix[r][c];
	right._n._matrix[r][c] = right._n._matrix[r][c + 1];
	right._n._matrix[r][c + 1] = temp;
	right._string = b._string + "R";

	unordered_set<board, board::hash>::const_iterator got = _uset.find(right);
	if (got == _uset.end()) {

		_queue.push(right);
		_uset.insert(right);

	}

#if 0
	_right = createBoard();
	_right->_parent = this;

	int temp = _right->_n._matrix[r][c];
	_right->_n._matrix[r][c] = _right->_n._matrix[r][c + 1];
	_right->_n._matrix[r][c + 1] = temp;
	_right->_string = _string + "R";
#endif // 0


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

#if 0
void e8p::pushInStack(board& b, queue<board*>& stack, unordered_set <board, board::hash>& uset) {

	if (b._up) {
		unordered_set<board, board::hash>::const_iterator got = uset.find(*(b._up));
		if (got == uset.end()) {

			stack.push(b._up);
			uset.insert(*b._up);

		}

	}

	if (b._down) {

		unordered_set<board, board::hash>::const_iterator got = uset.find(*(b._down));
		if (got == uset.end()) {

			stack.push(b._down);
			uset.insert(*b._down);

		}
	}

	if (b._left) {

		unordered_set<board, board::hash>::const_iterator got = uset.find(*(b._left));
		if (got == uset.end()) {

			stack.push(b._left);
			uset.insert(*b._left);

		}
	}

	if (b._right) {

		unordered_set<board, board::hash>::const_iterator got = uset.find(*(b._right));
		if (got == uset.end()) {

			stack.push(b._right);
			uset.insert(*b._right);

		}
	}


}

#endif // 0

//EOF

