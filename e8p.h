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

		cout << "In node const" << endl;

		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < N; ++j) {

				_matrix[i][j] = arr[i][j];
			}
		}

	}

	~node() {

		cout << "In node dest" << endl;
	}

	node(const node& n1) {

		cout << "In node copy const" << endl;

	}

	bool operator==(const node& n1) const {

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

		cout << "In board const" << endl;
		
	}

	~board() {

		cout << "In board dest" << endl;
	}

	board (const board& b1) : _n(b1._n) {

		cout << "In board copy const" << endl;
		
	}

	friend class node;
	friend class e8p;

	bool operator==(const board& b1) const {

		return (_n == b1._n);
	}

	bool operator!=(const board& b1) const {

		return !(_n == b1._n);
	}

	board* createBoard();
	void popoulateKids(int r, int c);
	//void findSpace(int& row, int& column);
	void swapDown(int r, int c);
	void swapUp(int r, int c);
	void swapLeft(int r, int c);
	void swapRight(int r, int c);

#if 0
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

		cout << "In e8p dest" << endl;
	}

	e8p(const e8p& from) = delete;
	e8p& operator=(const e8p& from) = delete;
	int get_num_moves() const;
	string get_solution() const;
	//void pushCombos(queue<board> & q, board& b);
	void findSpaceAndPopulate(board& b, int& row, int& col);
	void popoulateKids(board& b, int row, int col);
	//void pushInStack(board& b, stack<board*>& s, unordered_set<board, board::hash>& us);
#if 0
	void swapDown(board& b, int r, int c, queue<board>& q);
	node* swapUp(board& b, int r, int c);
	node* swapLeft(board& b, int r, int c);
	node* swapRight(board& b, int r, int c);
#endif // 0


	friend class board;

	bool isEqual() {

		return (_start == _finish);
	}
	

#if 0
	struct Hash {

		inline size_t operator() (const board& b) const {

			int sum = 0;

			for (int i = 0; i < N; ++i) {

				for (int j = 0; j < N; ++j) {

					sum += ((i*N) + j) * b._n._matrix[i][j];
				}
			}

			return (sum);

		}

	};
#endif // 0


	



private:

	board _start;
	board _finish;
	int _numMoves;
	string _solution;
	bool _foundSolution;

	



};

#if 1

using namespace std;

struct Hash {

public:

	size_t operator() (const board& b) const {

#if 1
		int sum = 0;

		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < N; ++j) {

				sum += ((i*N) + j) * b._n._matrix[i][j];
			}
		}

		return (sum);
#endif // 0

		//char* ch = reinterpret_cast<char* const>(&b);

	}

};
#endif // 0


#endif
//EOF


