/*
Q2. Minimum K to Reduce Array Within Limit

You are given a positive integer array nums.

For a positive integer k, define nonPositive(nums, k) as the minimum number of operations needed to make every element of nums non-positive. In one operation, you can choose an index i and reduce nums[i] by k.

Return an integer denoting the minimum value of k such that nonPositive(nums, k) <= k2.

 

Example 1:

Input: nums = [3,7,5]

Output: 3

Explanation:

When k = 3, nonPositive(nums, k) = 6 <= k2.

    Reduce nums[0] = 3 one time. nums[0] becomes 3 - 3 = 0.
    Reduce nums[1] = 7 three times. nums[1] becomes 7 - 3 - 3 - 3 = -2.
    Reduce nums[2] = 5 two times. nums[2] becomes 5 - 3 - 3 = -1.

Example 2:

Input: nums = [1]

Output: 1

Explanation:

When k = 1, nonPositive(nums, k) = 1 <= k2.

    Reduce nums[0] = 1 one time. nums[0] becomes 1 - 1 = 0.

 

Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 105

 
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long nonPositive(const vector<int>& nums, int k){
        long long count = 0;
        for(auto i: nums){
            count += (i+k-1)/k;
        }
        return count;
    }
    int minimumK(vector<int>& nums) {
        int left = 1;
        int right = max(*max_element(nums.begin(), nums.end()),
                (int)nums.size());
        int ans = right;
        while(left<=right){
            int middle = left + (right-left)/2;
            if(nonPositive(nums, middle) <= 1LL * middle * middle){
                ans = min(middle, ans);
                right = middle-1;
            }else{
                left = middle+1;
            }
        }
        return ans;        
    }
};