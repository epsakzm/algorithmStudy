// https://programmers.co.kr/learn/courses/30/lessons/64061
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    vector<int> stack;
    int mlen = moves.size();
    int blen = board.size();
    for (int i = 0; i < mlen; i++)
    {
        int idx = moves.at(i);
        for (int r = 0; r < blen; r++)
        {
            int pop = board[r][idx - 1];
            if (pop != 0)
            {
                if (!stack.empty() && stack.back() == pop)
                {
                    answer+=2;
                    stack.pop_back();
                }
                else
                {
                    stack.push_back(pop);
                }
                board[r][idx - 1] = 0;
                break;
            }
        }
    }
    return answer;
}

int main(void){
    vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};
    cout << solution(board,moves)<<endl;
    return 0;
}