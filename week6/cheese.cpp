#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;
    int d[N+1][N+1];
    memset(d, 0, sizeof(d));
    while (M--)
    {
        int x, y;
        cin >> x >> y;
        d[x][y] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            d[i][j] += max(d[i - 1][j], d[i][j - 1]);
        }
    }
    cout << d[N][N] << endl;
    return 0;
}