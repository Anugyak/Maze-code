//program of maze exploration using recursive function
#include<iostream>
#include<stdlib.h>
using namespace std;
//size of the maze
#define N 4

//recursive function that works for backtracking algorithm
bool Backtracking(int maze[N][N], int a, int b, int result[N][N])
{
    bool test;
	if (a == N - 1 && b == N - 1 && maze[a][b] == 1) {
		result[a][b] = 1;
		//return true if a and b is destination
		return true;													
	}
		if (a >= 0 && a < N && b >= 0 && b < N && maze[a][b] == 1)
{
		test= true;
}
else
{
	test= false;
}
	if (test == true) {
	
		if (result[a][b] == 1)
			return false;										//if the existing block is the path of the destination
		//mark a and b for the path
		result[a][b] = 1;											
		if (Backtracking(maze, a + 1, b, result) == true)			//move towards a direction
		{
			return true;
	}
		if (Backtracking(maze, a, b + 1, result) == true)			//if a doesnot provide the path move towards b
		{
			return true;
		}
		result[a][b] = 0;											//backtrack if both a and b doesnot give the required destination and also unmark a and b
		return false;
	}
	return false;
}

//function to check whether a and b is the valid index considering N*N maze in order to calculate the path// A function to check if x, y is valid index for N*N maze to find the path
bool valid(int maze[N][N], int a, int b)
{
	// if (a, b are outside the maze) return false
	if (a >= 0 && a < N && b >= 0 && b < N && maze[a][b] == 1)
		return true;
	return false;
}

// function that solves Rat in the created Maze problem
bool Maze(int maze[N][N])
{
	int result[N][N] = { { 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 }};
	if (Backtracking(maze, 0, 0, result) == false) {
		cout<<"Solution does not exist";
		return false;									//returns false if there is no path available
	}
		for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout<<" "<<result[i][j]<<" ";
		cout<<endl;
	}
	return true;										//displays that the path available is the form of 1's
}

//function to display the solution in the matrix[N][N]
void printSolution(int out[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout<<" "<<out[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
	int maze[N][N] = { { 1, 0, 1, 0 },
	                   { 1, 0, 0, 1 },
					{ 1, 1, 0, 0 },
					{ 0, 1, 1, 1 }  };
	Maze(maze);
	cout<<"Therefore this is the available path for the rat in maze using backtracking and is represented in 1's. ";
	return 0;
}
