#include<bts/stdc++.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

void swap (int *el1, int *el2){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArr (int arr[], int n){
  for(int i = 0; i < n; ++i){
    cout << arr[i] << ""; 
  }
  cout << "\n";
}

void shuffleArr(int arr[], int n){
  srand(time(NULL));
  for(int i = n - 1; i > 0; --i){
    int j = rand() % (i + 1);
    swap(&arr[i], &arr[j])
  }
}

int main(){
  int arr[] = {1, 2, 3, 4, 5}
  int n = sizeof(arr)/sizeof(arr[0]);
  shuffleArr(arr, n);
  printArr(arr, n);
  return 0
}
    
