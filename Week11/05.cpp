#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       /*map<char, int> hMap;
       for(int i = 0; i < S.size(); ++i){
           hMap[S[i]]++;
       }
       for(int i = 0; i < S.size(); ++i){
           if(hMap[S[i]] == 1)
                return S[i];
       }
       return '$';*/
      //256 ASCII characters
       vector<int> count(256, -1);
       for(int i = 0; i < S.size(); ++i){
         //if count is -1, element hasn't been encountered before
           if(count[S[i]] == -1)
             //Update to first occurring index
                count[S[i]] = i;
            else if(count[S[i]] >= 0)
                count[S[i]] = -2;
       }
       int min = INT_MAX;
       for(int i = 0; i < count.size(); ++i){
         //Find the minimum index recorded in the count array
           if(count[i] >= 0)
                min = min <= count[i] ? min: count[i];
       }
       if(min == INT_MAX)
        return '$';
        return S[min];
    }

};

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}
  // } Driver Code Ends
