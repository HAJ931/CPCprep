#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends


class Solution{
    public:
    // Function to return maximum of sum without adjacent elements
    ll FindMaxSum(ll arr[], ll n)
    {
        // Your code 
        long long include = arr[0], exclude = 0;
        for(long long i = 1; i < n; ++i){
            long long temp = include;
          //Sum including the current element will the sum of the current element and the sum so far, excluding the previous element
            include = exclude + arr[i];
          //The maximum sum excluding the current element would be the maximum of the sum including the previous element and the sum excluding the previous element
            exclude = temp > exclude ? temp : exclude;
        }
        return include > exclude ? include : exclude;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		ll n;
		cin>>n;
		ll a[n];
		
		//inserting money of each house in the array
		for(ll i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
