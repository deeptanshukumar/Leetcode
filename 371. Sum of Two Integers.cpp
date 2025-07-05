/*
371. Sum of Two Integers
Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
 

Constraints:

-1000 <= a, b <= 1000*/

#include <vector>
using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int carry = (a&b)<<1; //this is and, the output is left shifted to get carry
            a = a^b; //XOR this is sum without carry
            b = carry; //update carry
        }
        return a; //this is the final answer when carry is equal to 0
    }
};