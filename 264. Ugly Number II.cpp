/*
264. Ugly Number II
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.



Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.


Constraints:

1 <= n <= 1690*/

#include <vector>
using namespace std;
#include <algorithm>
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglynums = {1};
        int i2=0,i3=0,i5=0;
        while(uglynums.size()<=n){
            int next2 = uglynums[i2]*2;
            int next3 = uglynums[i3]*3;
            int next5 = uglynums[i5]*5;
            int nextnum = min({next2,next3,next5});
            uglynums.push_back(nextnum);
            if (nextnum == next2) i2++;
            if (nextnum == next3) i3++;
            if (nextnum == next5) i5++;
        }
        return uglynums[n-1];
    }    
};
