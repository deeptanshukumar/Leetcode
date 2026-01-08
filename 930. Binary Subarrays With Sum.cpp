/*
930. Binary Subarrays With Sum

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15

 

Constraints:

    1 <= nums.length <= 3 * 104
    nums[i] is either 0 or 1.
    0 <= goal <= nums.length

*/

#include <vector>
using namespace std;
class Solution {
public:
    int atmost(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int l = 0;
        int count = 0;
        int sum = 0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while(sum>goal){
                sum -= nums[l++];
            }
            count+=r-l+1;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal-1);
    }
};