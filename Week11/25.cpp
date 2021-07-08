// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
    #define lim 1000000007
  public:
    long long int nthFibonacci(long long int n){
        // code here
        if(n == 0)  
            return 0;
        if(n == 1 || n == 2)
            return 1;
        vector<long long> fib(n + 1, 0);
        fib[0] = 0;
        fib[1] = fib[2] = 1;
        for(int i = 3; i < n + 1; ++i){
            fib[i] = (fib[i - 1] + fib[i - 2]) % lim; 
        }
        return fib[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
