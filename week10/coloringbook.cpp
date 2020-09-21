//https://programmers.co.kr/learn/courses/30/lessons/1829
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool visited[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int cnt = 1;
int target;
int r, c;

void dfs(int x, int y, vector<vector<int>> picture)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= r || ny >= c || nx < 0 || ny < 0)
            continue;
        if (visited[nx][ny] || picture[nx][ny] == 0)
            continue;
        if(target != picture[nx][ny]) continue;
        visited[nx][ny] = true;
        cnt++;
        dfs(nx, ny, picture);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    r = m;
    c = n;
    vector<int> arr;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cnt = 1;
            if (!visited[i][j] && picture[i][j] != 0)
            {
                target = picture[i][j];
                number_of_area++;
                dfs(i, j, picture);
                arr.push_back(cnt);
            }
        }
    }
    max_size_of_one_area = *max_element(arr.begin(), arr.end());
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(void)
{
    // case1
    vector<int> v = solution(

    // 6, 4, {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}}

    // 5,5,{{1,1,1,1,1},{2,2,2,3,1},{0,0,0,0,1},{1,1,1,1,1},{5,1,5,1,5}}

    // 4,5,{{3,3,5,2,1},{1,1,1,1,1},{3,5,3,5,1},{1,1,1,1,1}}

    // 2,2,{{1,1},{1,1}}

    3,3,{{1,4,9},{2,3,8},{5,6,7}}
    
    );
    cout << v[0] << ',' << v[1] << endl;
    
    return 0;
}