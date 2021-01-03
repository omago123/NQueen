#include <iostream>
#include <vector>

using namespace std;

int cnt;

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

bool findpos(int* Q, int qsize, int level)
{
	if (level == qsize)
	{
		// findpos함수에 들어왔을 때 level값이 qsize와 같으면
		// 최종 배치가 성공했다는 의미이므로 출력하고 리턴
		printQueen(Q, qsize, cnt);
		return true;
	}
	for (int i = 0; i < qsize; i++)
	{
		// 현재 level에서 0부터 qsize-1까지 이동하면서 배치가 가능한지 검사
		if (check(Q, level, i) == false)	continue;	// 배치가 안되면 다음 위치로 이동

		// 배치가 가능하면 현재 level의 Queen위치를 저장하고 다음 레벨 배치로 이동
		Q[level] = i;
		findpos(Q, qsize, level + 1);
	}
	return false;
}

// Queen 찾기 함수
void Queen(int* Q, int qsize)
{
	for (int i = 0; i < qsize; i++)
	{
		// 최상위 level의 Queen위치를 설정하고 다음 level 배치로 이동
		Q[0] = i;
		findpos(Q, qsize, 1);
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
