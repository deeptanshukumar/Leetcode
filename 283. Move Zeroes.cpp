/*
283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 10^4
-231 <= nums[i] <= 2^31 - 1

*/
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0;i<size(nums)-1;i++){
            if(nums[i] == 0 && nums[i + 1] != 0){
                nums[i] = nums[i+1];
                nums[i+1] = 0;

                if (i > 0) i -= 2;
            }            
        }
    }
};