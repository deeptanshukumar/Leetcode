/*
14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.*/


#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str="";
        sort(strs.begin(), strs.end()); //alphabetically sorted!
        int index=0;
        while(index<strs[0].size()){
            if(strs[0][index]==strs[strs.size()-1][index])str+=strs[0][index++];
            else break;
        }
        return str;
    }
};