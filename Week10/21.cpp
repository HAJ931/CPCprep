

 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        vector<int> res(num);
        priority_queue<int, vector<int>, greater<int>> pq;
        int ptr = 0;
        for(int i = 0; i < K; ++i){
            pq.push(arr[i]);
        }
        for(int i = K; i < num; ++i){
            pq.push(arr[i]);
            res[ptr++] = pq.top();
            pq.pop();
        }
        while(pq.size()){
            res[ptr++] = pq.top();
            pq.pop();
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends
