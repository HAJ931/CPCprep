
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int left = 0, right = n - 1;
	    while(left <= right){
	        int mid = left + (right - left) / 2;
	        if((mid == 0 || arr[mid - 1] < arr[mid]) && arr[mid] == x){
	            int lo = mid;
	            int hi = n - 1;
	            while(lo <= hi){
	                int mi = lo + (hi - lo) / 2;
	                if((mi == n - 1 || arr[mi + 1] > arr[mi]) && arr[mi] == x){
	                    return mi - mid + 1;
	                }
	                else if(arr[mi] > x)
	                    hi = mi - 1;
	               else lo = mi + 1;
	            }
	            return 1;
	        }
	        else if(arr[mid] < x)
	            left = mid + 1;
	       else right = mid - 1;
	    }
	    return 0;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
