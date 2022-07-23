#include<bits/stdc++.h>

using namespace std;

void fitShelves(int wall, int large, int small) {
    int minSpace = wall % large;
    int numOfLarge = wall / large, numOfSmall = 0;
    int tempNumOfLarge = wall / large, tempNumOfSmall = 0;
    while(wall >= small){
        ++tempNumOfSmall;
        wall -= small;
        tempNumOfLarge = wall / large;
        int currSpace = wall % large;
        if(currSpace < minSpace){
            minSpace = currSpace;
            numOfLarge = tempNumOfLarge;
            numOfSmall = tempNumOfSmall;
        }
    }
    cout << minSpace << " " << numOfLarge << " " << numOfSmall << endl;
}

int main() {
    int wall, m, n;
    cin >> wall >> m >> n;
    fitShelves(wall, m, n);
}
