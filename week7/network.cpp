// https://programmers.co.kr/learn/courses/30/lessons/43162

#include <bits/stdc++.h>

using namespace std;

int answer = 0;
bool visited[201];

void dfs(int x, int n, vector<vector<int>> computers)
{
    visited[x] = true;
    for (int i = 0; i < n; i++)
    {
        if (computers[x][i] && !visited[i]) // computer[1][2] -> 1
        {
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            answer++;
            dfs(i, n, computers);
        }
    }
    return answer;
}

int main(void)
{
    vector<vector<int>> v = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
    cout << solution(1, v) << endl;
    
    return 0;
}