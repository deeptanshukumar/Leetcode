/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]

 

Constraints:

    1 <= n <= 8

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findstrings(vector<string> &ans, string s, int open, int close){
        if(open==0&&close==0){
            ans.push_back(s);
            return;
        }
        if(open>0){
            s+="(";
            findstrings(ans, s, open-1, close);
            s.pop_back();
        }
        if(close>0){
            if(open<close){
                s+=")";
                findstrings(ans, s, open, close-1);
                s.pop_back();
            }
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        findstrings(ans, "", n,n);
        return ans;
    }
};