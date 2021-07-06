#include <bits/stdc++.h>
using namespace std;

int myStrCmp(string s1, string s2){
    int i = 0;
    while(i < s1.length() && i < s2.length()){
      //Use XOR to invert the 6th bit of the ASCII value of the character
      //This is because doing so converts the ASCII value of lowercase character into uppercase and vice versa
        if(s1[i] == s2[i] || s1[i] == (s2[i] ^ 32)){
            ++i;
            continue;
        }
        if((s1[i] | 32) < (s2[i] | 32))
            return -1;
        else
            return 1;
    }
    if(s1.length() < s2.length())
        return -1;
    if(s1.length() > s2.length())
        return 1;
    return 0;
}

int main() {
	string s1 = "Geekslorgeeks";
	string s2 = "geeksforgeeks";
	cout << myStrCmp(s1, s2);
}
