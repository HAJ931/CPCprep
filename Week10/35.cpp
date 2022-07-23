//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int assignMiceHoles(int N , int M[] , int H[]) {
        // code here
        int maxTime = INT_MIN;
        sort(M, M + N);
        sort(H, H + N);
        for(int i = 0; i < N; ++i){
            if(abs(H[i] - M[i]) > maxTime)
                maxTime = abs(H[i] - M[i]);
        }
        return maxTime;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        
        int M[N],H[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>M[i];
        for(int i=0 ; i<N ; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.assignMiceHoles(N,M,H) << endl;
    }
    return 0;
}
// } Driver Code Ends
