#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int maxCount = 0, currCount = 0, maxRow = -1;
	    for(int i = 0; i < n; ++i){
	        currCount = 0;
	        for(int j = 0; j < m; ++j){
	            if(arr[i][j])
	                ++currCount;
	           if(currCount == m)
	                return i;
	        }
	        if (currCount > maxCount){
	            maxCount = currCount;
	            maxRow = i;
	        }
	    }
	    return maxRow;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
