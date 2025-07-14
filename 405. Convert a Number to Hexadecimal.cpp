/*
405. Convert a Number to Hexadecimal
Given a 32-bit integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.

All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.

Note: You are not allowed to use any built-in library method to directly solve this problem.

 

Example 1:

Input: num = 26
Output: "1a"
Example 2:

Input: num = -1
Output: "ffffffff"
 

Constraints:

-231 <= num <= 231 - 1*/

#include <string>
#include <algorithm>
#include <cstdint>
using namespace std;
class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0";
        string hexmap = "0123456789abcdef"; //this is a hexmap
        unsigned int n = num; //to handle negative numbers, we use unsigned int
        string result; 

        while(n>0){
            int digit = n&0xf; //get the last 4 bits 
            result +=hexmap[digit]; //map it to the hex character
            n>>=4; //right shift by 4 to process the next 4 bits
        }

        reverse(result.begin(),result.end()); //reverse the result to get the correct order
        return result;
    }
};