// https://programmers.co.kr/learn/courses/30/lessons/42883
#include <bits/stdc++.h>

using namespace std;

vector<int> v;

string solution(string number, int k)
{
    string answer = "";
    int N = number.length() - k; // 6

    while (N--)
    {
        int maxNumber, last;
        maxNumber = last = 0;
        for (int j = 0; j < number.length() - N; j++)
        //0, 1, 2, 3, 4
        {
            if (maxNumber < number[j])
            {
                maxNumber = number[j];
                last = j;
            }
        }
        answer += maxNumber;
        number = number.substr(last+1, -1);
    }
    return answer;
}

int main(void)
{
    cout << solution("4177252841", 4) << endl;
    return 0;
}