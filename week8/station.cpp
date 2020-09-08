// https://programmers.co.kr/learn/courses/30/lessons/12979
#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int pos = 1;
    int sIdx = 0;
    while(pos <= n){
        if(pos >= stations[sIdx] - w && pos <=stations[sIdx] + w)
            pos = stations[sIdx++] + w + 1;
        else{
            pos += w * 2 + 1;
            answer++;
        }
    }
    return answer;
}

int main(void)
{
    cout << solution(16, {9}, 2);
    return 0;
}