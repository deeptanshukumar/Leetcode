/*
189. Rotate Array
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?*/


#include <vector>
#include <algorithm>
using namespace std;
//brute force soultion with O(n+k) time complexity and O(k) space complexity
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //brute force        
        int n = nums.size();
        k=k%n;  //to handle cases where k is greater than n where we can just rotate the array k%n times
        vector<int> temp(nums.end()-k,nums.end());
        for(int i=n-k-1;i>=0;i--){
            nums[i+k] = nums[i];
        }
        for(int i=0;i<temp.size();i++){
            nums[i]=temp[i];
        }
    }
};

//optimized solution with O(2*n) time complexity and O(1) space complexity
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};