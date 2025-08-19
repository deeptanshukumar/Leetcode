/*
161. Majority Element
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109*/

#include <vector>
#include <algorithm>
using namespace std;
//moore's voting algorithm implementation
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                count=1;
                element = nums[i];
            } else if(nums[i]==element){
                count++;
            } else {
                count--;
            }
        }
        return element;
    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

