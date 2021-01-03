#include <iostream>
#include <vector>

using namespace std;

// row�� idx�� ��ġ�� �� �ִ��� �˻�
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

// Queen ã�� �Լ�
void Queen(int* Q, int qsize)
{
	int i, row = 1;
	int count = 0;
	while (1)
	{
		// loop�� ��� ���� �˻�
		if (row < 0)	break;
		if (qsize <= Q[row])	// ���� row�� ���� QSIZE�� ��� ���
		{
			row--;				// row�� �ϳ� �ٿ��ְ� �ٽ� loop
			if (0 <= row)	Q[row]++;
			continue;
		}

		// ���� row������ ��ġ �˻�
		for (i = Q[row]; i < qsize; i++)
		{
			Q[row] = i;
			if (check(Q, row, i))	// ��ġ�����ϸ� loop ����
				break;
		}
		if (i == qsize)
		{
			// ��ġ�� �����ߴٴ� �ǹ��̹Ƿ� row�� �ϳ� �ٿ��� �ٽ� �ݺ��Ѵ�.
			row--;
			if (0 <= row)
			{
				Q[row]++;
				Q[row + 1] = 0;	// �ٸ� row���� �ʱ�ȭ ���ش�.
			}
		}
		else
		{
			if (row + 1 == qsize)
			{
				printQueen(Q, qsize, count);	// ������ row�� Queen�� ��ġ�� ���
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
	int qsize = 4;				// ����Ʈ qsize ����
	if (2 <= argc)				// argument���� 2���� ũ��
	{
		qsize = atoi(argv[1]);	// 2��° �Ķ���͸� qsize�� �Է�
		if (qsize < 4)			// qsize�� 4���� ������
		{
			printf("Not valid Queen Size! it must be greater than 3!\n");
			return 0;
		}
	}
	// qsize��ŭ �޸� �Ҵ� & �ʱ�ȭ
	int* Q = new int[qsize];
	memset(Q, 0, sizeof(int) * qsize);

	// Queen ã�� �Լ� ȣ��
	Queen(Q, qsize);

	// �޸� ����
	delete[] Q;
	printf("Done!\n");
	return 1;
}
