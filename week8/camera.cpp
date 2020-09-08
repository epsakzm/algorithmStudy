// https://programmers.co.kr/learn/courses/30/lessons/42884
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int solution(vector<vector<int>> routes)
{
    int answer = 0;
    sort(routes.begin(), routes.end());
    int pos = routes[0][1];
    for(int i = 1;i < routes.size(); i++)
    {
        if(pos < routes[i][0]){
            answer++;
            pos = routes[i][1];
        }
        if(pos > routes[i][1])
            pos = routes[i][1];
    }
    return answer + 1;
}

int main(void)
{
    vector<vector<int>> v = {{-20, 15}, {-14, -5}, {-18, -13}, {-5, -3}};
    cout << solution(v) << endl;
    return 0;
}