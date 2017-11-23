#pragma once
/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: e8p.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has e8p class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef e8p_H
#define e8p_H

#include "../util/util.h"
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>


static const int N = 3;



/*----------------------------------------------------------------
Node definition
-----------------------------------------------------------------*/
class node {
public:

	node(const int arr[N][N]) : _matrix{ 0 } {

		//cout << "In node const" << endl;

		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < N; ++j) {

				_matrix[i][j] = arr[i][j];
			}
		}

	}

	~node() {

		//cout << "In node dest" << endl;
	}

#if 1
	node(const node& n1) {

		//cout << "In node copy const" << endl;

		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < N; ++j) {

				_matrix[i][j] = n1._matrix[i][j];

			}
		}

	}
#endif // 0


	bool operator==(const node& n1) const {
		//cout << "In node == operator" << endl;
		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {

				if (_matrix[i][j] != n1._matrix[i][j]) {

					return false;
				}
			}
		}

		return true;
	}

	friend class board;
	friend class e8p;

//private:

	int _matrix[N][N];

#if 0
	node* _up;
	node* _down;
	node* _left;
	node* _right;
	node* _parent;
#endif // 0

};



/*----------------------------------------------------------------
Declaration of board
-----------------------------------------------------------------*/
class board {
public:

	board(const int arr1[N][N]) : _n(arr1), _string(""), _up(nullptr), _down(nullptr), _left(nullptr), _right(nullptr), _parent(nullptr) {

		//cout << "In board const" << endl;
		
	}

	~board() {

		//cout << "In board dest" << endl;
	}


	board(const board& b1) : _n(b1._n) {

		//cout << "In board copy const" << endl;

		_string = b1._string;
		_up = b1._up;
		_down = b1._down;
		_left = b1._left;
		_right = b1._right;
		_parent = b1._parent;

	}



	friend class node;
	friend class e8p;

	bool operator==(const board& b1) const {
		//cout << "In board == operator" << endl;
		return (_n == b1._n);
	}

	bool operator!=(const board& b1) const {

		return !(_n == b1._n);
	}

	board* createBoard();
	void popoulateKids(int r, int c);
	//void findSpace(int& row, int& column);
#if 0
	void swapDown(int r, int c);
	void swapUp(int r, int c);
	void swapLeft(int r, int c);
	void swapRight(int r, int c);
#endif // 0


#if 1
	struct hash {

		inline int operator() (const board& b) const {

			int sum = 0;

			for (int i = 0; i < N; ++i) {

				for (int j = 0; j < N; ++j) {

					sum += ((i*N) + j) * b._n._matrix[i][j];
				}
			}

			return sum;

		}

	};
#endif // 0


//private:

	node _n;
	string _string;

	board* _up;
	board* _down;
	board* _left;
	board* _right;
	board* _parent;

};

/*----------------------------------------------------------------
Declaration of e8p class
-----------------------------------------------------------------*/
class e8p {
public:
	static const int N = 3;

	e8p(const int s[N][N], const int f[N][N]);

	~e8p() {

		//cout << "In e8p dest" << endl;
	}

	e8p(const e8p& from) = delete;
	e8p& operator=(const e8p& from) = delete;
	int get_num_moves() const;
	string get_solution() const;
	//void pushCombos(queue<board> & q, board& b);
	void findSpaceAndPopulate(board& b, int& row, int& col);
	void popoulateKids(board& b, int row, int col);
	//void pushInStack(board& b, stack<board*>& s, unordered_set<board, board::hash>& us);
	void pushInStack(board& b, queue<board>& s, unordered_set<board, board::hash>& us);
#if 1
	void swapDown(board& b, int r, int c);
	void swapUp(board& b, int r, int c);
	void swapLeft(board& b, int r, int c);
	void swapRight(board& b, int r, int c);
#endif // 0


	friend class board;

	bool isEqual() {

		return (_start == _finish);
	}
	

#if 0
	struct hash {

		inline size_t operator() (const board& b) const {

			

#if 1
			int sum = 0;

			for (int i = 0; i < N; ++i) {

				for (int j = 0; j < N; ++j) {

					sum += ((i*N) + j) * b._n._matrix[i][j];
				}
			}

			cout << "HEREH!!!! - " <<sum<< endl;

			return (sum);
#endif // 0

		}

	};
#endif // 0


	



private:

	board _start;
	board _finish;
	int _numMoves;
	string _solution;
	bool _foundSolution;

	unordered_set<board, board::hash> _uset;
	queue<board> _queue;

	



};


#endif
//EOF


