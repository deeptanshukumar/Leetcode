/*
62. Unique Paths

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:

Input: m = 3, n = 7
Output: 28

Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

 

Constraints:

    1 <= m, n <= 100

 
*/
#include <algorithm>
using namespace std;
class Solution {
public:
    long long ncr(int n, int r) {
        if(r<0||r>n) return 0;
        if(r==0||r==n) return 1;
        if(r>n/2) r=n-r;
        long long ans = 1;
        for(int i=1; i<=r; i++){
            ans = ans*(n-i+1)/i; 
        }
        return ans;
    }
    int uniquePaths(int m, int n) {
        return ncr(m+n-2, m-1);
    }
};