#include <iostream>

#define qsize 4

using namespace std;

bool check(int* Q,int row, int level)
{
	for(int i=0; i<row; i++){
	if (Q[i] == Q[level]) //column
		return false;
    if (level - i == abs(Q[i] - Q[level])) // diagnoal
		return false;
	}
	return true;
}

int main()
{
	int* Q = new int[qsize];

	return 0;
}
