#include <iostream>

#define N 4

using namespace std;


int A[N][N] = { 0, };

bool Check(int row, int col)
{
	for (int i = 0; i < row; i++) {
		if (A[i][col] == 1)
			return false;
		int l = col - (row - i);
		if (l >= 0 && A[i][l] == 1)
			return false;
		int r = col + (row - i);
		if (r < N && A[i][r] == 1)
			return false;

	}
	return true;
};

void PrintQueen()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%2d", A[i][j]);
		}
		printf("\n\n");
	}
	printf("\n\n");
}


int main()
{


	for (int i = 0; i < N; i++)
	{
		memset(A[0], 0, sizeof(int) * N);
		A[0][i] = 1;
		for (int j = 0; j < N; j++) {
			memset(A[1], 0, sizeof(int) * N);
			A[1][j] = 1;
			if (Check(1, j) == false) continue;

			for (int k = 0; k < N; k++) {
				memset(A[2], 0, sizeof(int) * N);
				A[2][k] = 1;
				if (Check(2, k) == false) continue;

				for (int m = 0; m < N; m++) {
					memset(A[3], 0, sizeof(int) * N);
					A[3][m] = 1;
					if (Check(3, m) == false) continue;
					PrintQueen();
				}
			}
		}
	}

}

