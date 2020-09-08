// https://programmers.co.kr/learn/courses/30/lessons/43163
#include<bits/stdc++.h>

using namespace std;

bool one(string str1, string str2){
    int cnt = 0;
    for(int i = 0; i < str1.length(); i++){
        if(str1[i] != str2[i]){
            cnt++;
            if(cnt>2)return false;
        }
    }
    return cnt == 1;
}

int bfs(string begin, string target, vector<string> words){
    int len = begin.length();
    queue<pair<string, int>> q;
    q.push({begin, 0});
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        string str = temp.first;
        int count = temp.second;
        if(str == target)
            return count;
        for(auto word : words)
            if(one(str, word))
                q.push({word, count+1});
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    answer = bfs(begin, target, words);
    return answer;
}

int main(void){
    string begin = "hit";
    string target = "cog";
    vector<string> v = {"hot","dot","dog","lot","log","cog"};
    cout << solution(begin, target, v)<< endl;
    return 0;
}