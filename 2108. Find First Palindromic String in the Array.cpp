/*
2108. Find First Palindromic String in the Array
Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.

 

Example 1:

Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.
Example 2:

Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".
Example 3:

Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists only of lowercase English letters.
*/
//manual solution
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool palidromic(string word){
        string oldstr = word;
        int left=0,right=word.size()-1;
        while(left<right){
            swap(word[left], word[right]);
            left++;
            right--;
        }
        return word==oldstr? true:false;
    }
    
    string firstPalindrome(vector<string>& words) {
        for(auto word:words){
            if(palidromic(word)) return word;
        }
        return "";
    }
};

//stl approach
class Solution {
public:   
    string firstPalindrome(vector<string>& words) {
        for(auto word:words){
            if(string(word.rbegin(), word.rend())==word) return word;
        }
        return "";
    }
};