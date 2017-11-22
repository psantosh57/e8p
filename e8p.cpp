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

		unordered_set <board, board::hash> uset;
		queue<board*> queue;
		//stack<board*> stack;

		//Push the first board in hash 
		uset.insert(_start);
		unordered_set<board, board::hash>::const_iterator got = uset.find(_start);

		int row = 0;
		int col = 0;
		findSpaceAndPopulate(_start, row, col);
		//pushInStack(_start, stack, uset);
		pushInStack(_start, queue, uset);

		cout << "Here" << endl;

		board* parent = &_start;
		_solution = _start._string;

		while (!queue.empty()) {

			//board* temp = stack.top();
			//stack.pop();
			board* temp = queue.front();
			queue.pop();

			_numMoves++;
			

			if (*temp == _finish) {

				_solution = temp->_string;
				
				break;
			}
			else {
				findSpaceAndPopulate(*temp, row, col);
				//pushInStack(*temp, stack, uset);
				pushInStack(*temp, queue, uset);
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

		//_solution = "";


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
		
		b.swapDown(r, c);
	} 
	else if (r == 1) {

		b.swapDown(r, c);
		b.swapUp(r, c);
	}
	else if (r == 2) {

		b.swapUp(r, c);
	}

	if (c == 0) {

		b.swapRight(r, c);
	}
	else if (c == 1) {

		b.swapRight(r, c);
		b.swapLeft(r, c);
	}
	else if (c == 2) {

		b.swapLeft(r, c);

	}

}

void board::swapDown(int r, int c) {

	_down = createBoard();
	_down->_parent = this;

	int temp = _down->_n._matrix[r][c];
	_down->_n._matrix[r][c] = _down->_n._matrix[r + 1][c];
	_down->_n._matrix[r + 1][c] = temp;
	_down->_string = _string + "D";

}

void board::swapUp(int r, int c) {

	_up = createBoard();
	_up->_parent = this;

	int temp = _up->_n._matrix[r][c];
	_up->_n._matrix[r][c] = _up->_n._matrix[r - 1][c];
	_up->_n._matrix[r - 1][c] = temp;
	_up->_string = _string + "U";

}

void board::swapLeft(int r, int c) {

	_left = createBoard();
	_left->_parent = this;

	int temp = _left->_n._matrix[r][c];
	_left->_n._matrix[r][c] = _left->_n._matrix[r][c - 1];
	_left->_n._matrix[r][c - 1] = temp;
	_left->_string = _string + "L";

}

void board::swapRight(int r, int c) {

	_right = createBoard();
	_right->_parent = this;

	int temp = _right->_n._matrix[r][c];
	_right->_n._matrix[r][c] = _right->_n._matrix[r][c + 1];
	_right->_n._matrix[r][c + 1] = temp;
	_right->_string = _string + "R";

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

#if 1
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

