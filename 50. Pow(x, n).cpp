/*
50. Pow(x, n)
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104
*/
//this code is correct for small values of n but is not efficient for large n due to stack overflow in recursion.
//also TC of this code is O(n) which is not optimal for large n.
#include <cmath>
#include <cstdlib>
using namespace std;
class Solution {
public:
    double pow(double x,int n){
        if(n==1) return x;
        return x*pow(x,n-1);
    }
    double myPow(double x, int n) {
        double ans = pow(x,abs(n));
        if(n<0) return 1/ans;
        return ans;
    }
};


//RIGHT SOLUTION
//TC is log(n) as we are using dividing n by 2 in each step.
class Solution {
public:
    double power(double x, long long N){
        if(N==0) return 1;
        double half = power(x,  N/2);
        if(N%2==0) return half*half;
        return x*half*half;
    }
    double myPow(double x, int n) {
        long long N = n;
        if(n<0){
            x = 1/x;
            N = -N;
        }
        return power(x,N);
    }
};  //this is the recursive solution
//Iterative solution
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(n<0){
            x = 1/x;
            N = -N;
        }
        double result = 1;
        while(N){
            if(N%2==1) result*=x;
            x*=x;
            N/=2;
        }
        return result;
    }
};