/*
125. Valid Palindrome
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.*/

#include <string>
#include <cctype>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string clearstr = "";
        for(char c:s){
            if(isalnum(c)) clearstr+=tolower(c);
        }
        string revstr = "";
        for(int i=size(clearstr); i>0;i--) revstr+=clearstr[i-1];
        return clearstr==revstr?true:false;
    }  
};