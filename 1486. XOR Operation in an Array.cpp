/*
1486. XOR Operation in an Array
You are given an integer n and an integer start.

Define an array nums where nums[i] = start + 2 * i (0-indexed) and n == nums.length.

Return the bitwise XOR of all elements of nums.

 

Example 1:

Input: n = 5, start = 0
Output: 8
Explanation: Array nums is equal to [0, 2, 4, 6, 8] where (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8.
Where "^" corresponds to bitwise XOR operator.
Example 2:

Input: n = 4, start = 3
Output: 8
Explanation: Array nums is equal to [3, 5, 7, 9] where (3 ^ 5 ^ 7 ^ 9) = 8.
 

Constraints:

1 <= n <= 1000
0 <= start <= 1000
n == nums.length
*/

#include <vector>
using namespace std;
class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums;
        for(int i=0;i<n;i++) nums.push_back(start+2*i);
        int ans=nums[0];
        for(int i=1;i<n;i++){
            ans=ans^nums[i];
        }
        return ans;
    }
};