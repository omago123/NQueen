#include <iostream>

#define N 4

using namespace std;

int Q[N][N] = { 0, };

bool Check(int row, int col)
{
	for (int i = 0; i < row; i++) 
	{	// (row,col) 위쪽이 막혔을 때
		if (Q[i][col] == 1)
			return false;
		// 대각으로 막혔을때
		int l = col - (row - i); // 왼쪽
		if (l>=0 && Q[i][l] == 1)
			return false;
		int r = col + (row - i); // 오른쪽
		if (r <N && Q[i][r] == 1)
			return false;
	}
	return true;
}

void PrintQueen()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%2d ", Q[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
		


int main()
{
	for (int i = 0; i < N; i++)
	{
		memset(Q[0], 0, sizeof(int) * N);
		Q[0][i] = 1;
		for (int j = 0; j < N; j++) {
			memset(Q[1], 0, sizeof(int) * N);
			Q[1][j] = 1;
			if (Check(1, j) == false) continue;

			for (int k = 0; k < N; k++) {
				memset(Q[2], 0, sizeof(int) * N);
				Q[2][k] = 1;
				if (Check(2, k) == false) continue;

				for (int l = 0; l < N; l++) {
					memset(Q[3], 0, sizeof(int) * N);
					Q[3][l] = 1;
					if (Check(3, l) == false) continue;
					PrintQueen();
				}
			}
		}
	}

			
		
	
}