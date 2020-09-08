// https://programmers.co.kr/learn/courses/30/lessons/64063
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#define MAX 200001

using ll = long long;
using namespace std;

vector<ll> parent(MAX, 0);

int find(int x)
{
    if (parent[x] == 0)
        return x;
    return find(parent[x]);
}

vector<long long> solution(long long k, vector<long long> room_number)
{
    vector<long long> answer;
    for (int i = 0; i < room_number.size(); i++)
    {
        ll number = room_number[i];
        ll next;
        if (!parent[number])
            next = number;
        else
            next = find(number);

        answer.push_back(next);
        parent[next] = find(next + 1);
    }
    return answer;
}

int main(void)
{
    ll k = 10;
    vector<ll> room_number = {1, 3, 4, 1, 3, 1};
    vector<ll> answer = solution(k, room_number);
    for (auto x : answer)
    {
        cout << x << ' ';
    }
    return 0;
}