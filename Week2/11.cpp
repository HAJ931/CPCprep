#include <iostream>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int sum = 0, leftSum = 0, rightSum;
        if(n == 1)
            return 1;
        for(int i = 0; i < n; ++i){
            sum += a[i];
        }
        rightSum = sum - a[0];
        for(int i = 1; i < n - 1; ++i){
            leftSum += a[i - 1];
            rightSum -= a[i];
            if(leftSum == rightSum)
                return (i + 1);
        }
        return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
