/*
69. Sqrt(x)
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1
*/
#include <cmath>
using namespace std;
// Brute force solution
class Solution {
public:
    int mySqrt(int x) {
        for (int i=0;i<=x;i++) {
            if((1LL*i*i<= x) && (1LL*(i+1)*(i+1)>x)) return i;
        }
        return -1;
    }
};
// Optimized version using binary search
//explanation: We can use binary search to find the square root of x. The idea is to maintain a range [left, right] and check the middle value. If mid*mid is less than or equal to x, we move left to mid + 1, otherwise we move right to mid.
#include <cmath>
class Solution {
public:
    int mySqrt(int x) {
        if (x == 1||x==0) return x==0? 0 : 1; 
        int left = 1, right = x;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid > x / mid) right = mid;
            else left = mid + 1;
        }
        return left - 1;
    }
};
