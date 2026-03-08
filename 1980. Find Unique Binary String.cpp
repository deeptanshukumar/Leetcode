/*
1980. Find Unique Binary String

Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.

Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.

Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.

 

Constraints:

    n == nums.length
    1 <= n <= 16
    nums[i].length == n
    nums[i] is either '0' or '1'.
    All the strings of nums are unique.
*/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int binarytoint(string& number){
        int sum = 0;
        for(auto i:number){
            sum = sum*2+(i-'0');
        }
        return sum;
    }
    string intToBinary(int num, int n){
        string ans(n, '0');
        for(int i = n-1; i >= 0; i--){
            ans[i] = (num % 2) + '0';
            num /= 2;
        }
        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<int, int>freq;
        for(auto &i:nums){
            freq[binarytoint(i)]++;
        }
        int min = 0;
        string num = "";
        for(int i=0;i<nums[0].size();i++){
            num+='1';
        }
        int max = binarytoint(num);
        for(int i=min;i<=max;i++){
            if(freq[i]!=1) return intToBinary(i, nums[0].size());
        }
        return "";        
    }
};