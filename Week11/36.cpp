#include <bits/stdc++.h>
using namespace std;

int turnOffRightSet(int n){
    //n - 1 will flip the rightmost set bit,
    //as well as all the bits to the right of the
    //rightmost set bit and the bits to its left stay
    //the same so when bitwise & is done, we get 
    //the required result
    return n & (n - 1);
}

int main() {
	//code
	int n = 16;
	cout << turnOffRightSet(n);
	return 0;
}
