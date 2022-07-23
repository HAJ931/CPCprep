#include<bits/stdc++.h>

using namespace std;

int maxThieves(vector<char>& people, int k) {
    int caught = 0;
    int n = people.size();
    int policePtr = 0, thiefPtr = 0;
    while(true){
        while(policePtr < n && people[policePtr] != 'P')
            ++policePtr;
        while(thiefPtr < n && people[thiefPtr] != 'T')
            ++thiefPtr;
        if(policePtr >= n || thiefPtr >= n)
            break;
        if(abs(policePtr - thiefPtr) <= k){
            ++policePtr;
            ++thiefPtr;
            ++caught;
        }
        else if(policePtr < thiefPtr) {
            ++policePtr;
        }
        else {
            ++thiefPtr;
        }
    }
    return caught;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<char> people(n);
    for(int i = 0; i < n; ++i){
        cin >> people[i];
    }
    cout << maxThieves(people, k) << endl;
}
