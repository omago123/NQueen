#include <iostream>
#include <vector>

using namespace std;

// row의 idx에 위치할 수 있는지 검사
bool check(int* Q, int row, int idx)
{
	for (int i = 0; i < row; i++)
	{
		if (Q[i] == idx)	// column
			return false;
		if (row - i == abs(Q[i] - idx))	// diagonal
			return false;
	}
	return true;
}

void printQueen(int* Q, int qsize, int& count)
{
	printf("[%d]", ++count);
	for (int j = 0; j < qsize; j++)
		printf("%d ", Q[j]);
	printf("\n");
}

// Queen 찾기 함수
void Queen(int* Q, int qsize)
{
	int i, row = 1;
	int count = 0;
	while (1)
	{
		// loop를 벗어날 조건 검사
		if (row < 0)	break;
		if (qsize <= Q[row])	// 현재 row의 값이 QSIZE를 벗어날 경우
		{
			row--;				// row를 하나 줄여주고 다시 loop
			if (0 <= row)	Q[row]++;
			continue;
		}

		// 현재 row에서의 배치 검사
		for (i = Q[row]; i < qsize; i++)
		{
			Q[row] = i;
			if (check(Q, row, i))	// 배치가능하면 loop 종료
				break;
		}
		if (i == qsize)
		{
			// 배치에 실패했다는 의미이므로 row를 하나 줄여서 다시 반복한다.
			row--;
			if (0 <= row)
			{
				Q[row]++;
				Q[row + 1] = 0;	// 다름 row값을 초기화 해준다.
			}
		}
		else
		{
			if (row + 1 == qsize)
			{
				printQueen(Q, qsize, count);	// 마지막 row에 Queen이 배치된 경우
				row--;
				if (0 <= row)			Q[row]++;
				if (row < qsize - 1)	Q[row + 1] = 0;
			}
			else
			{
				row++;
				if (row < qsize)	Q[row] = 0;
			}
		}
	}
}

int main(int argc, char* argv[])
{
	int qsize = 4;				// 디폴트 qsize 설정
	if (2 <= argc)				// argument수가 2보다 크면
	{
		qsize = atoi(argv[1]);	// 2번째 파라미터를 qsize로 입력
		if (qsize < 4)			// qsize가 4보다 작으면
		{
			printf("Not valid Queen Size! it must be greater than 3!\n");
			return 0;
		}
	}
	// qsize만큼 메모리 할당 & 초기화
	int* Q = new int[qsize];
	memset(Q, 0, sizeof(int) * qsize);

	// Queen 찾기 함수 호출
	Queen(Q, qsize);

	// 메모리 해제
	delete[] Q;
	printf("Done!\n");
	return 1;
}
