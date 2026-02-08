/*
1781. Sum of Beauty of All Substrings

The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

    For example, the beauty of "abaacc" is 3 - 1 = 2.

Given a string s, return the sum of beauty of all of its substrings.

 

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

Example 2:

Input: s = "aabcbaa"
Output: 17

 

Constraints:

    1 <= s.length <= 500
    s consists of only lowercase English letters.

 */
#include <vector>
#include <string>
#include <climits>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            unordered_map<int, int>freq;
            for(int j=i;j<=n-1;j++){
                freq[s[j]-'a']++;
                int minf = INT_MAX;
                int maxf = 0;
                for(auto i:freq){
                    minf = min(minf, i.second);
                    maxf = max(maxf, i.second);
                }
                sum+=maxf-minf;
            }
        }
        return sum;
    }
};
