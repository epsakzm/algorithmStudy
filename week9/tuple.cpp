// https://programmers.co.kr/learn/courses/30/lessons/64065
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
//s = {{4,2,3},{3},{2,3,4,1},{2,3}}
bool comp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second > p2.second;
}
void push(string &s, vector<int> &v)
{
    int tmp = stoi(s);
    v[tmp] += 1;
    s.clear();
}
vector<int> solution(string s)
{
    vector<int> answer;
    // first : 숫자, second :
    vector<int> v(100001, 0);
    vector<pair<int, int>> tempv;
    string temp = "";
    bool in = false;

    //앞 뒤 {} 제거
    for (int i = 1; i < s.length() - 1; i++)
    {
        char c = s[i];
        if (c == '{')
            in = true;
        else if (c == '}')
        {
            in = false;
            push(temp, v);
        }
        else if (c >= '0' && c <= '9')
            temp += c;
        else if (c == ',')
            if (in)
                push(temp, v);
    }
    for (int i = 0; i < v.size(); i++)
        if (v[i])
            tempv.push_back({i, v[i]});
    sort(tempv.begin(), tempv.end(), comp);
    for (auto x : tempv)
        answer.push_back(x.first);
    return answer;
}

int main(void)
{
    string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
    vector<int> v = solution(s);
    for (auto x : v)
        cout << x << ' ';
    return 0;
}