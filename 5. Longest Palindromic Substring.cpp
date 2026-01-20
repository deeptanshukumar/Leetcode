/*
5. Longest Palindromic Substring

Given a string s, return the longest

in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

 

Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int expand(string &s, int left, int right){
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            right++;
            left--;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        int start =0;
        int maxlen=1;
        for(int i=0;i<s.size();i++){
            int len1=expand(s, i,i);
            int len2 = expand(s, i, i+1);
            int len = max(len1, len2);
            if(len>maxlen){
                maxlen = len;
                start = i-(len-1)/2;
            }
        }
        return s.substr(start, maxlen);
    }
};