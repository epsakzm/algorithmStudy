// https://programmers.co.kr/learn/courses/30/lessons/67259]
#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int>> board)
{
    queue<pair<pair<int, int>, int>> q;
    bool visited[26][26];
    int arr[26][26];
    int size = board.size();
    int cost = 0x7f7f7f7f;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    q.push({{0, 0}, -1});
    visited[0][0] = true;
    arr[0][0] = 0;
    while (!q.empty())
    {
        auto temp = q.front();
        int nx = temp.first.first;
        int ny = temp.first.second;
        int direction = temp.second;

        q.pop();

        if (nx == size - 1 && ny == size - 1)
        {
            if (cost > arr[nx][ny])
                cost = arr[nx][ny];
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int cx = nx + dx[i];
            int cy = ny + dy[i];

            if (cx < 0 || cy < 0 || cx >= size || cy >= size || board[cx][cy] == 1)
                continue;

            int temp_cost = 0;

            if (direction == -1 || direction == i)
                temp_cost = arr[nx][ny] + 100;
            else if (direction != i)
                temp_cost += arr[nx][ny] + 600;

            if ((board[cx][cy] == 0 && !visited[cx][cy]) || arr[cx][cy] > temp_cost)
            {
                arr[cx][cy] = temp_cost;
                q.push({{cx, cy}, i});
                visited[cx][cy] = true;
            }
        }
    }
    return cost;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    answer = bfs(board);
    return answer;
}

int main(void)
{
    vector<vector<int>> v{{0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}};
    cout << solution(v) << endl;
    
    return 0;
}
