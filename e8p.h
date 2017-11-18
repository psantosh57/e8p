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

private:

	int _matrix[N][N];
};



/*----------------------------------------------------------------
Declaration of board
-----------------------------------------------------------------*/
class board {
public:

	board(const int arr1[N][N]) : _n(arr1), _up(nullptr), _down(nullptr), _left(nullptr), _right(nullptr) {

		cout << "In board const" << endl;

	}

	~board() {

		cout << "In board dest" << endl;
		_up = nullptr;
		_down = nullptr;
		_left = nullptr;
		_right = nullptr;
	}

	friend class node;
	friend class e8p;

	bool operator==(const board& b1) const {

		return (_n == b1._n);
	}

	bool operator!=(const board& b1) const {

		return !(_n == b1._n);
	}


private:

	node _n;

	board* _up;
	board* _down;
	board* _left;
	board* _right;

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
	void pushCombos(queue<board> & q, board& b);
	void findSpace(board& b, int& row, int& column);
	board* swap(board& b, int r, int c, const char* str);

	friend class board;

	bool isEqual() {

		return (_start == _finish);
	}
	
	struct hash {

		inline size_t operator() (const board& b) const {

			int sum = 0;

			for (int i = 0; i < N; ++i) {

				for (int j = 0; j < N; ++j) {

					sum += ((i*N) + j) * b._n._matrix[i][j];
				}
			}

			return sum;

		}

	};

	



private:

	board _start;
	board _finish;
	int _numMoves;
	string _solution;
	bool _foundSolution;

	



};

#endif
//EOF


