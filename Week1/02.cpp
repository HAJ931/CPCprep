//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        int uni = 0, in = 0, i = 0, j = 0;
        int uniSet[m + n], interSet[m > n ? n : m];
        sort(a, a + n);
        sort(b, b + m);
        while(i < n || j < m){
            if(a[i] < b[j]){
                if(uniSet[uni-1] != a[i]){
                    uniSet[uni] = a[i];
                    ++uni;
                }
                ++i;
            }
            else if(a[i] > b[j]){
                if(uniSet[uni-1] != b[j]){
                    uniSet[uni] = b[j];
                    ++uni;
                }
                ++j;
            }
            else{
                if(uniSet[uni-1] != b[j]){
                    uniSet[uni] = b[j];
                    ++uni;
                }
                if(interSet[uni-1] != b[j]){
                    interSet[in] = b[j];
                    ++in;
                }
                ++i;
                ++j;
            }
        }
        if(i < n){
            while(i < n){
                if(uniSet[uni-1] != a[i]){
                    uniSet[uni] = a[i];
                    ++uni;
                }
                ++i;
            }
        }
        else{
            while(j < m){
                if(uniSet[uni-1] != b[j]){
                    uniSet[uni] = b[j];
                    ++uni;
                }
                ++j;
            }
        }
        
        return uni;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
