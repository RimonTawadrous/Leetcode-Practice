#include <bits/stdc++.h>
using namespace std;

int scoreOfParentheses(string s)
{
    stack<int> scores;
    int score = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if(s[i] == '('){
            scores.push(score);
            score = 0;
        }else{
            score = scores.top() + max(score*2,1);
            scores.pop();
        }
    }

    return score;
}

int main()
{
    return 0;
}