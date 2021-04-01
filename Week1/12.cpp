#include <iostream>
using namespace std;

struct Pair{
    int min;
    int max;
};

struct Pair minMax(int Arr[], int n){
    Pair ans;
    int i;
    if(n == 1){
        ans.min = Arr[0];
        ans.max = Arr[0];
        return ans;
    }
    else if(n == 2){
        ans.min = (Arr[0] > Arr[1]) ? Arr[1] : Arr[0];
        ans.max = (Arr[0] > Arr[1]) ? Arr[0] : Arr[1];
        return ans;
    }
    if(n % 2 == 0){
        ans.min = (Arr[0] > Arr[1]) ? Arr[1] : Arr[0];
        ans.max = (Arr[0] > Arr[1]) ? Arr[0] : Arr[1];
        i = 2;
    }
    else{
        ans.min = Arr[0];
        ans.max = Arr[0];
        i = 1;
    }
    for(; i < n - 1; i = i + 2){
        if(Arr[i] >= Arr[i + 1]){
            if(Arr[i] > ans.max)
                ans.max = Arr[i];
            if(Arr[i + 1] < ans.min)
                ans.min = Arr[i + 1];
        }
        else{
            if(Arr[i + 1] > ans.max)
                ans.max = Arr[i + 1];
            if(Arr[i] < ans.min)
                ans.min = Arr[i];
        }
    }
    return ans;
}

int main() {
    int Arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    struct Pair ans = minMax(Arr, n);
	cout<<"Minimum element: " << ans.min << "\nMaximum element: " << ans.max << "\n";
	return 0;
}
