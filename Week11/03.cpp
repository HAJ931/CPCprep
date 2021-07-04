#include<bits/stdc++.h>
using namespace std;
//Linear Time Complexity (Not sure if legal)
void revString(string& a, int i){
    if(i == a.length())
        return;
    revString(a, i + 1);
    cout << a[i];
}
//Quadratic time complexity
void revString(string a){
    if(a.size() == 0)
        return;
    revString(a.substr(1));
    cout << a[0];
    
}

int main(){
    string a = "Hello World!";
    revString(a, 0);
    cout << "\n";
    revString(a);
}
