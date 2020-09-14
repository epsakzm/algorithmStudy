https://programmers.co.kr/learn/courses/30/lessons/64062
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(int n, vector<int> stones, int k)
{
    int cnt = 0;
    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i] <= n) cnt++;
        else cnt = 0;
        if (cnt >= k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k)
{
    int answer = 0;
    int first = *min_element(stones.begin(), stones.end());
    int last = *max_element(stones.begin(), stones.end());
    while (first <= last)
    {
        int mid = (first + last) / 2;
        if (check(mid, stones, k))
            first = mid + 1;
        else
            last = mid - 1;
    }
    answer = first;
    return answer;
}

int main(void)
{
    cout << solution({2, 4, 5, 3, 2, 1, 4, 2, 5, 1}, 3);
    return 0;
}
