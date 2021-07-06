#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        int maxSoFar = 0;
        int curr = 0, maxRepIndex = -1;
        vector<int> found(256, -1);
        for(int i = 0; i < S.length(); ++i){
            if(found[S[i]] != -1){
                if(maxSoFar < curr)
                    maxSoFar = curr;
                int startIndex = found[S[i]] > maxRepIndex ? found[S[i]]: maxRepIndex;
                if(maxRepIndex < startIndex)
                    maxRepIndex = startIndex;
                curr = i - startIndex - 1;
            }
            found[S[i]] = i;
            ++curr;
            //cout << "Index " << i << ": " << curr << "\n";  
            if(curr > maxSoFar)
                maxSoFar = curr;
        }
        return maxSoFar;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } Driver Code Ends
