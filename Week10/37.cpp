// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    private: 
    static bool cmp (struct Item a, struct Item b){
        float r1 = (float) a.value / a.weight;
        float r2 = (float) b.value / b.weight;
        return r1 > r2;
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, cmp);
        double val = 0;
        for(int i = 0; i < n; ++i){
            if(arr[i].weight < W){
                W -= arr[i].weight;
                val += arr[i].value;
            }
            else {
                val += (double) arr[i].value / (double) arr[i].weight * W;
                break;
            }
        }
        return val;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
