#include <iostream>
using namespace std;

const int N = 6;

class graf
{
private:
    int matrix[N][N];

public:
    graf(int input[N][N])
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                matrix[i][j] = input[i][j];
    }

    void print()
    {
        cout << "Matrytia sumijnosti:\n";
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }

    void povn()
    {
        bool p = true;
        for (int i = 0; i < N && p; ++i)
            for (int j = 0; j < N; ++j)
                if (i != j && matrix[i][j] == 0)
                    p = false;

        cout << "\nGraf ";
        if (p)
            cout << "e povnym\n";
        else
            cout << "ne e povnym\n";
    }

    void printspys()
    {
        cout << "\nSpysok sumijnosti:\n";
        for (int i = 0; i < N; ++i)
        {
            cout << i + 1 << ": ";
            for (int j = 0; j < N; ++j)
                if (matrix[i][j] != 0)
                    cout << j + 1 << "(" << matrix[i][j] << ") ";
            cout << endl;
        }
    }

    void servid()
    {
        int total = 0, k = 0;
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                if (matrix[i][j] != 0)
                {
                    total += matrix[i][j];
                    k++;
                }
        float avg = 0;
        avg = (float)total / k;

        cout << "\nSerednya dovjina shliahu: " << avg << endl;
    }

    void poshukisol()
    {
        int k = 0;
        int isol[N];

        cout << "\nIzoliovani punkty:\n";
        for (int i = 0; i < N; ++i)
        {
            int l = 0;
            int minDist = 20000, nearest = -1;
            for (int j = 0; j < N; ++j)
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
                isol[k] = i;
                k++;
                cout << "punkt " << i + 1 << ", blyjchyi do " << nearest + 1 << ", vidstani: " << minDist << endl;
            }
        }

        cout << "\nKilkisti izoliovanyh: " << k << endl;
    }

    void trymist()
    {
        int maxSum = -1;
        int a = -1, b = -1, c = -1;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j || matrix[i][j] == 0)
                    continue;
                for (int k = 0; k < N; k++)
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
        cout << "\nNaydovshyi marshrut mij 3 mistamy:\n";
        cout << "(" << a + 1 << ") --- " << matrix[a][b] << " --- (" << b + 1 << ") --- " << matrix[b][c] << " --- (" << c + 1 << ")\n";
    }

    /*void odynmarsh()
  {

  }*/
};

int main()
{
    int a[N][N] =
    {
          {0, 0, 2, 0, 5, 0},
          {0, 0, 6, 4, 0, 0},
          {2, 6, 0, 0, 0, 9},
          {0, 4, 0, 0, 4, 0},
          {8, 0, 0, 4, 0, 0},
          {0, 0, 9, 0, 0, 0}
    };

    graf g(a);

    g.print();
    g.povn();
    g.printspys();
    g.servid();
    g.poshukisol();
    g.trymist();
    //g.odynmarsh();

    return 0;
}
