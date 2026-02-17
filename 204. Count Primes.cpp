/*
204. Count Primes


Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:

Input: n = 0
Output: 0

Example 3:

Input: n = 1
Output: 0

 

Constraints:

    0 <= n <= 5 * 106

*/

#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        int count=1;
        vector<bool> seen(n,false);
        for(int i=3;i<n;i+=2){
            if(!seen[i]){
                count++;
                for(long long j=1LL*i*i;j<n;j+=2*i){
                    seen[j]=true;
                }
            }
        }
        return count;
    }
};