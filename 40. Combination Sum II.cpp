/*
40. Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

 

Constraints:

    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void combinationrecursion(vector<int> &candidates, int target, int index, vector<vector<int>> &ans, vector<int> &list){
        if(target==0){
            ans.push_back(list);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            list.push_back(candidates[i]);
            combinationrecursion(candidates, target-candidates[i], i+1, ans, list);
            list.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> list;
        sort(candidates.begin(), candidates.end());
        combinationrecursion(candidates, target, 0, ans, list);
        return ans;   
    }
};