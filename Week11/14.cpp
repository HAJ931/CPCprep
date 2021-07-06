// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string removeChars(string string1, string string2) {
        // code here
        vector<bool> count(256, false);
        for(int i = 0; i < string2.size(); ++i){
            count[string2[i]] = true;
        }
        for(int i = 0; i < string1.size(); ++i){
            if(count[string1[i]]){
                string1.erase(string1.begin() + i);
                --i;
            }
        }
        return string1;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string string1,string2;
        cin >> string1; 
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1,string2) << endl;
    }
    return 0;
}
  // } Driver Code Ends
