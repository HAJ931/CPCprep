

 // } Driver Code Ends


class Solution{
    public:
    // Function to find the subarray with given sum k
    // arr: input array
    // n: size of array
    vector<int> subarraySum(int arr[], int n, int s){
        
        // Your code here
        vector<int> ans;
        int sum = arr[0], i = 0, j = 0;
        for(j = 1; j <= n; ++j){
          //
            while(sum > s && i < j - 1){
                sum -= arr[i];
                ++i;
            }
            if(sum == s){
                ans.push_back(i + 1);
                ans.push_back(j);
                return ans;
            }
            if(j < n)
                sum += arr[j];
        }
        ans.push_back(-1);
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
