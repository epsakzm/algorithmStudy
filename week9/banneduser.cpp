// https://programmers.co.kr/learn/courses/30/lessons/64064
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

bool visited[8];
set<string> s;

bool same(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s2[i] == '*')
            continue;
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

void dfs(int index, vector<string> user_id, vector<string> banned_id)
{

    if (index == banned_id.size())
    {
        string temp = "";
        for (int i = 0; i < user_id.size(); i++)
            if (visited[i])
                temp += to_string(i);
        s.insert(temp);
        return;
    }

    for (int i = 0; i < user_id.size(); i++)
    {
        if (!same(user_id[i], banned_id[index]) || visited[i])
            continue;
        visited[i] = true;
        dfs(index + 1, user_id, banned_id);
        visited[i] = false;
    }
    return;
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    int answer = 0;

    dfs(0, user_id, banned_id);

    answer = s.size();
    return answer;
}

int main(void)
{
    //case1
    // vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    // vector<string> banned_id = {"fr*d*", "abc1**"};
    //case2
    vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id = {"*rodo", "*rodo", "******"};
    cout << solution(user_id, banned_id);
    return 0;
}