#include<bits/stdc++.h>
using namespace std;

void retOccurrence(string str){
    map<char, int> hMap;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == ' ')
            continue;
        hMap[str[i]]++;
    }
    for(auto i: hMap){
        if(i.second > 1)
            cout << i.first << ": " << i.second << "\n";
    }
}

int main(){
    string str = "Geeks for Geeks";
    retOccurrence(str);
}
