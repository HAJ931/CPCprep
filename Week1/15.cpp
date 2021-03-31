#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void segregateEvenOdd(int arr[], int n) {
	    // code here
	    int modArr[n];
	    sort(arr, arr + n);
	    int i = 0, j = 0, k = n - 1;
	    for(; i < n; ++i){
	        if(arr[i] % 2 == 0){
	            modArr[j] = arr[i];
	            ++j;
	        }
	        else{
	            modArr[k] = arr[i];
	            --k;
	        }
	    }
	    for(i = 0, k = n - 1; i < n; ++i){
	        if(i < j)
	            arr[i] = modArr[i];
	       else{
	            arr[i] = modArr[k];
	            --k;
	       }
	    }
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
