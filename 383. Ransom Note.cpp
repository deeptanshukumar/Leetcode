/*
383. Ransom Note
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.*/

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
//using seperate count method
class Solution {
public:
    int count(string userstring, char target){
        int count = 0;
        for (char c : userstring) {
            if(c == target) count++;
        }
        return count;
    }

    bool canConstruct(string ransomNote, string magazine) {
        bool value = true;
        for(char c:ransomNote){
            if(!(count(magazine,c)>=count(ransomNote,c))){
                value = false;
                break;
            }
        }
        return value;
    }
};

//using count method from STL
#include <algorithm>
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool value = true;
        for(char c:ransomNote){
            if(!(count(magazine.begin(),magazine.end(),c)>=count(ransomNote.begin(),ransomNote.end(),c))){
                value = false;
                break;
            }
        }
        return value;
    }
};

//hashing method to be done