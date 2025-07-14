/*
349. Intersection of Two Arrays
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000*/


//unordered_set solution
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> n1(nums1.begin(),nums1.end()); 
        unordered_set <int> common; 
        for(int i:nums2){
            if((n1.count(i))) common.insert(i);
        }
        return vector<int>(common.begin(),common.end());
    }
};

//2 pointers solution
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        unordered_set<int> ans;
        int i=0;
        int j=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]==nums2[j]){
                ans.insert(nums1[i]);
                i++;j++;
            }
            else if(nums1[i]>nums2[j]) j++;
            else i++;
        }
        return vector<int> (ans.begin(), ans.end());
    }
};

//hashmap solution
#include <vector>   
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i:nums1){
            mpp[i]=1; //storing unique elements in the map
        }
        for(int i:nums2){
            if(mpp.find(i)!=mpp.end()){
                ans.push_back(i);
                mpp.erase(i); //to ensure uniqueness, we erase the element after adding it to the answer
            }
        }
        return ans;
    }
};