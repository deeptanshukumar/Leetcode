/*
242. Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?*/

#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
//sorting solution
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

//hashmap solution
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpps,mppt;
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            mpps[s[i]]++;
            mppt[t[i]]++;
        }
        return mpps==mppt;
    }
};

// if we are required to write in just 1 map, we can make a map
// of one string and then in another loop decrement it if found. in case it isnt found. just return false btw.



//online code from leetcode with 0ms
#include <string>
#include <vector>
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);

        for (char& ch : s) {
            count[ch - 'a']++;
        }
        for (char& ch : t) {
            count[ch - 'a']--;
        }

        bool allZero = all_of(begin(count), end(count), [](int n) { 
            return n == 0; 
        });
        
        return allZero;
    }
};