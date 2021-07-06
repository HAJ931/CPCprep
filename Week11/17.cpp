#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here
  string res = "";
  for(int i = 0; i < src.length(); ++i){
      int count = 0;
      int left = i;
      while(i < src.length() && src[i] == src[left]){
          ++count;
          ++i;
      }
      res += src[left];
      res += count + '0';
      --i;
  }
  return res;
}     
 
