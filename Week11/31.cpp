// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long X) {
        // code here
        int count = 32;
        long long rev = 0;
        while(X){
            rev <<= 1;
            rev |= X & 1;
            X >>= 1;
            --count;
        }
        rev <<= count;
        return rev;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}  // } Driver Code Ends
