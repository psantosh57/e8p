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
#include <queue>
#include <string>

static const int N = 3;

/*----------------------------------------------------------------
Node definition
-----------------------------------------------------------------*/
class node {
public:

	node(const int arr[N][N]) : _matrix(nullptr) {

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

private:

	int **_matrix;
};



/*----------------------------------------------------------------
Declaration of board
-----------------------------------------------------------------*/
class board{
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

private:

	node _n; 

	node* _up;
	node* _down;
	node* _left;
	node* _right;
  
};

/*----------------------------------------------------------------
Declaration of e8p class
-----------------------------------------------------------------*/
class e8p{
public:
  static const int N = 3 ;
  
  e8p(const int s[N][N], const int f[N][N]) : _start(s), _finish(f) {
  
	  cout << "In e8p const" << endl;
  
  }

  ~e8p() {

	  cout << "In e8p dest" << endl;
  }

  e8p(const e8p& from) = delete;
  e8p& operator=(const e8p& from) = delete;
  int get_num_moves() const ;
  string get_solution() const ;

  friend class board;

private:

	board _start;
	board _finish;
 
};



#endif
//EOF

