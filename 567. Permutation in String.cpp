/*
567. Permutation in String
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.*/

#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size()>s2.size()) return false;
        vector<int> s1freq(26,0), windowfreq(26,0);

        for(char ch:s1) s1freq[ch-'a']++;

        for(int i=0;i<s2.size()-s1.size()+1;i++){
            windowfreq = vector<int>(26, 0);
            for(char ch:s2.substr(i,s1.size())) windowfreq[ch-'a']++;
            if(windowfreq==s1freq) return true;
        }
        return false;
    }
};