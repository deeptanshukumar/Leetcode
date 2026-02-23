/*
3848. Check Digitorial Permutation

You are given an integer n.

A number is called digitorial if the sum of the factorials of its digits is equal to the number itself.

Determine whether any permutation of n (including the original order) forms a digitorial number.

Return true if such a permutation exists, otherwise return false.

Note:

    The factorial of a non-negative integer x, denoted as x!, is the product of all positive integers less than or equal to x, and 0! = 1.
    A permutation is a rearrangement of all the digits of a number that does not start with zero. Any arrangement starting with zero is invalid.

 

Example 1:

Input: n = 145

Output: true

Explanation:

The number 145 itself is digitorial since 1! + 4! + 5! = 1 + 24 + 120 = 145. Thus, the answer is true.

Example 2:

Input: n = 10

Output: false

Explanation:​​​​​​​

10 is not digitorial since 1! + 0! = 2 is not equal to 10, and the permutation "01" is invalid because it starts with zero.

 

Constraints:

    1 <= n <= 109

*/

#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int factorial(int f){
        int mul = 1;
        for(int i=1;i<=f;i++){
            mul*=i;
        }
        return mul;
    }
    bool isDigitorialPermutation(int n) {
        int temp = n;
        int sum=0;
        while(temp){
            sum+=factorial(temp%10);
            temp/=10;
        }
        string a = to_string(sum);
        string b = to_string(n);
        if(a.length()!=b.length()) return false;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a==b;
    }
};