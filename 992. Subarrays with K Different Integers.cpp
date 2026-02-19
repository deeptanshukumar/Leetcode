/*
992. Subarrays with K Different Integers

Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

    For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

 

Constraints:

    1 <= nums.length <= 2 * 104
    1 <= nums[i], k <= nums.length

 */

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraysWithDistinct(vector<int>& nums, int k){
        unordered_map<int, int> freq;
        int l=0;
        int r=0;
        int count = 0;

        while(r<nums.size()){
            freq[nums[r]]++;
            if(freq.size()>k){
                while(freq.size()>k){
                    freq[nums[l]]--;
                    if(freq[nums[l]]==0) freq.erase(nums[l]);
                    l++;
                }
            }
            if(freq.size()<=k) count+=r-l+1;
            r++;            
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithDistinct(nums, k)-subarraysWithDistinct(nums, k-1);
    }
};

