#include <iostream>
using namespace std;

const int SIZE = 4;

class Graph
{
private:
	int matrix[SIZE][SIZE];
public:
	Graph(int input[SIZE][SIZE])
	{
		for (int i = 0; i < SIZE; ++i)
			for (int j = 0; j < SIZE; ++j)
				matrix[i][j] = input[i][j];
	}

	void print()
	{
		cout << "Adjacency matrix:\n";
		for (int i = 0; i < SIZE; ++i)
		{
			for (int j = 0; j < SIZE; ++j)
				cout << matrix[i][j] << " ";
			cout << endl;
		}
	}

	void printAdjacencyList()
	{
		cout << "Adjacency list:\n";
		for (int i = 0; i < SIZE; ++i)
		{
			cout << i + 1 << ": ";
			for (int j = 0; j < SIZE; ++j)
				if (matrix[i][j] != 0)
					cout << j + 1 << "(" << matrix[i][j] << ") ";
			cout << endl;
		}
	}

	void isGraphFull()
	{
		bool isFull = true;
		for (int i = 0; i < SIZE; ++i)
			for (int j = 0; j < SIZE; ++j)
				if (i != j && matrix[i][j] == 0)
					isFull = false;

		cout << "\nGraph ";
		if (isFull)
			cout << "is full.\n";
		else
			cout << "isn't full.\n";
	}

	void averagePathLength()
	{
		int total = 0, k = 0;
		for (int i = 0; i < SIZE; ++i)
			for (int j = i + 1; j < SIZE; ++j)
				if (matrix[i][j] != 0)
				{
					total += matrix[i][j];
					k++;
				}
		float avg = 0;
		avg = (float)total / k;

		cout << "\nAverage path length: " << avg << endl;
	}

	void findIsolatedLocalities()
	{
		int k = 0;
		int isolated[SIZE];

		cout << "\nIsolated localities:\n";
		for (int i = 0; i < SIZE; ++i)
		{
			int l = 0;
			int minDist = 20000, nearest = -1;
			for (int j = 0; j < SIZE; ++j)
			{
				if (matrix[i][j] != 0)
				{
					l++;
					if (matrix[i][j] < minDist)
					{
						minDist = matrix[i][j];
						nearest = j;
					}
				}
			}
			if (l == 1)
			{
				isolated[k] = i;
				k++;
				cout << "Locality " << i + 1 << "is closer to " << nearest + 1 << ", distanse: " << minDist << endl;
			}
		}

		cout << "\nNumber of isolated localities: " << k << endl;
	}

	void findMaxPath()
	{
		int maxSum = -1;
		int a = -1, b = -1, c = -1;

		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (i == j || matrix[i][j] == 0)
					continue;
				for (int k = 0; k < SIZE; k++)
				{
					if (k == i || k == j || matrix[j][k] == 0)
						continue;

					int sum = matrix[i][j] + matrix[j][k];
					if (sum > maxSum)
					{
						maxSum = sum;
						a = i;
						b = j;
						c = k;
					}
				}
			}
		}
		cout << "\nMax path between 3 cities:\n";
		cout << "(" << a + 1 << ") --- " << matrix[a][b] << " --- (" << b + 1 << ") --- " << matrix[b][c] << " --- (" << c + 1 << ")\n";
	}
};

int main()
{
	int matrix[SIZE][SIZE] = 
	{
	{0, 0, 4, 0},
	{0, 0, 6, 3},
	{4, 6, 0, 7},
	{0, 3, 7, 0}
	};

	Graph graph(matrix);

	graph.print();
	graph.isGraphFull();
	graph.printAdjacencyList();
	graph.averagePathLength();
	graph.findIsolatedLocalities();
	graph.findMaxPath();

	return 0;
}