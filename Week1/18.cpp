#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // coode here 
        int count1 = 0, count2 = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] == 0)
                ++count1;
            if(a[i] == 1)
                ++count2;
        }
        
        for(int i = 0; i < n; ++i){
            if(count1 != 0){
                a[i] = 0;
                --count1;
            }
            else if(count2 != 0){
                a[i] = 1;
                --count2;
            }
            else{
                a[i] = 2;
            }
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends
