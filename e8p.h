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
#include <unordered_set>
#include <queue>
#include <string>


static const int N = 3;

/*----------------------------------------------------------------
Node definition
-----------------------------------------------------------------*/
class node {
public:

	node(const int arr[N][N]) : _matrix{ 0 } {

		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < N; ++j) {

				_matrix[i][j] = arr[i][j];
			}
		}

	}

	~node() {};

	node(const node& n1) {

		//cout << "In node copy const - " << endl;
		

		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < N; ++j) {

				_matrix[i][j] = n1._matrix[i][j];

			}
		}

	}


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
	static int _count;

	int _matrix[N][N];

};




/*----------------------------------------------------------------
Declaration of board
-----------------------------------------------------------------*/
class board {
public:

	board(const int arr1[N][N]) : _n(arr1), _string("") {}

	~board() {};


	board(const board& b1) : _n(b1._n) {

		_string = b1._string;

	}

	friend class node;
	friend class e8p;

	bool operator==(const board& b1) const {
		return (_n == b1._n);
	}

	bool operator==(const board*& b1) {
		return (_n == b1->_n);
	}

	bool operator!=(const board& b1) const {

		return !(_n == b1._n);
	}

	board* createBoard();

	struct Hash {

		inline int operator() (const board* b) const {

			int sum = 0;

			for (int i = 0; i < N; ++i) {

				for (int j = 0; j < N; ++j) {

					sum += ((i*N) + j) * (b->_n._matrix[i][j]);
				}
			}

			return sum;

		}

	};

	struct Compare {

		inline int operator() (const board* b1, const board* b2) const {

			return (b1->_n == b2->_n);

		}

	};

	node _n;
	string _string;

};

/*----------------------------------------------------------------
Declaration of e8p class
-----------------------------------------------------------------*/
class e8p {
public:
	static const int N = 3;

	e8p(const int s[N][N], const int f[N][N]);

	~e8p() {

		while (!queue.empty()) {

			board* temp = queue.front();
			queue.pop();
			uset.erase(temp);
			delete temp;
		}

		unordered_set<board*, board::Hash, board::Compare>::const_iterator got = uset.begin();
		while (got != uset.end()) {

			delete *got;
			got++;

		}	

	}

	e8p(const e8p& from) = delete;
	e8p& operator=(const e8p& from) = delete;
	int get_num_moves() const;
	string get_solution() const;
	void findSpaceAndPopulate(board& b, int& row, int& col);
	void popoulateKids(board& b, int row, int col);
	void swapDown(board& b, int r, int c);
	void swapUp(board& b, int r, int c);
	void swapLeft(board& b, int r, int c);
	void swapRight(board& b, int r, int c);

	friend class board;

private:

	board _start;
	board _finish;
	int _numMoves;
	string _solution;
	bool _foundSolution;

	unordered_set<board*, board::Hash, board::Compare> uset;
	queue<board*> queue;

};


#endif
//EOF


