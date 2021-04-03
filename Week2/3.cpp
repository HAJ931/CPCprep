#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A, A + n);
        int count = n, j, k, sum;
        for(int i = 0; i < n; ++i){
            if(A[i] > X){
                count = i;
                break;
            }
        }
        for(int i = 0; i < count-2; ++i){
            j = i + 1;
            k = count - 1;
            sum = X - A[i];
            while (j != k){
                if(A[j] + A[k] > sum)
                    --k;
                else if(A[j] + A[k] < sum)
                    ++j;
                else return true;
            }
        }
        return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends
