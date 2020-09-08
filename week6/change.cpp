//https://programmers.co.kr/learn/courses/30/lessons/12907
#include <bits/stdc++.h>
#define endl '\n'
#define MOD 1000000007
using ll = long long;
using namespace std;

int solution(int n, vector<int> money)
{
    ll d[n + 1];
    memset(d, 0, sizeof(d));

    d[0] = 1;
    for (int i = 0; i <= n; i++)
        if (i % money[0] == 0)
            d[i] = 1;

    for (int i = 1; i < money.size(); i++)
        for (int j = money[i]; j <= n; j++)
            d[j] += d[j - money[i]] % MOD;

    return d[n];
}

int main(void)
{
    cout << solution(5, {1, 2, 5}) << endl;
    return 0;
}