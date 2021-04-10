
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    // code here
	    long long maxProd = -INT_MAX, currMax = 1, minProd = 1;
	    for(int i = 0; i < n; ++i){
	        if(arr[i] > 0){
	            currMax *= arr[i];
	            minProd = (minProd * arr[i] < 1) ? minProd * arr[i] : 1;
	        }
	        else if (arr[i] == 0){
	            currMax = 1;
	            minProd = 1;
	        }
	        else{
	            long long temp = currMax;
	            currMax = (minProd * arr[i] > 1) ? minProd * arr[i] : 1;
	            minProd = temp * arr[i];
	        }
	        if(maxProd < currMax)
	            maxProd = currMax;
	    }
	    
	    return maxProd;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
