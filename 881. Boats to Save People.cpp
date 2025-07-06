/*
881. Boats to Save People
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
 

Constraints:

1 <= people.length <= 5 * 104
1 <= people[i] <= limit <= 3 * 104*/

//right code
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int left=0,right=people.size()-1;
        int count=0;
        while(left<=right){
            if(people[left]+people[right]<=limit){
                left++;
            }
            right--;
            /* another logic (same thing) ----------
            if(people[left]+people[right]<=limit){
                left++;
                right--;
            } else {
                right--;
            }
            ----------------------------------------*/
            count++;            
        }
        return count;
    }
};









/*
wrong code assuming pairing people from begining one by one instead of thinking
of pairing heaviest with lightest

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int index = 0;
        int count = 0;
        while(index<people.size()){
            if(people[index]>=limit){
                count++;
                index++;
            } else {
                int sum=people[index];
                while(index+1<people.size()&&sum+people[index+1]<=limit){
                    sum+=people[index+1];
                    index++;
                }
                index++;
                count++;
            }
        }
        return count;
    }
};*/